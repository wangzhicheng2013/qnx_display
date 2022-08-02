#include "qnx_screen_display.h"
int main() {
	qnx_screen_display *pDisplay = new qnx_screen_display;
	if (!pDisplay) {
		return -1;
    }
    if (pDisplay->init()) {
		return -1;
    }
	
	pDisplay->set_image_pos(0, 0);
	pDisplay->set_image_size(1280, 720);
	pDisplay->set_clip_size(1280, 720);
	int ret = pDisplay->prepare_image();
    if (ret) {
        LOG_E("prepare for image failed, error = %d", ret);
    }
	else {
		Display->display_image((const char *)"");
	}
	if (pDisplay) {
		delete pDisplay;
        pDisplay = NULL;
    }
	return 0;
}