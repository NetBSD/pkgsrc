$NetBSD: patch-common_terminal.c,v 1.1 2026/04/13 15:49:39 kikadf Exp $

* Wsconsio patch from OpenBSD

--- common/terminal.c.orig	2024-10-30 19:43:26.000000000 +0000
+++ common/terminal.c
@@ -22,6 +22,7 @@
 #define K_DISABLE K_RAW
 #define FRSIG     SIGIO
 #elif defined(__NetBSD__)
+#include <dev/wscons/wsconsio.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
 #define K_ENABLE  K_XLATE
 #define K_DISABLE K_RAW
@@ -201,7 +202,19 @@ int terminal_set_process_switching(int f
 		.acqsig = enable ? SIGUSR2 : 0,
 		.frsig = FRSIG,
 	};
-
+	struct vt_mode current_mode;
+	if (ioctl(fd, VT_GETMODE, &current_mode) == -1) {
+		log_errorf("Could not query VT mode for %d: %s",
+		    fd, strerror(errno));
+		return -1;
+	}
+	if (current_mode.mode == mode.mode &&
+	    current_mode.relsig == mode.relsig &&
+	    current_mode.acqsig == mode.acqsig &&
+	    current_mode.frsig == mode.frsig) {
+		log_debugf("%s: %d already in mode %d", __func__, fd, enable);
+		return 0;
+	}
 	if (ioctl(fd, VT_SETMODE, &mode) == -1) {
 		log_errorf("Could not set VT mode to %s process switching: %s",
 			   enable ? "enable" : "disable", strerror(errno));
@@ -242,11 +255,20 @@ int terminal_ack_acquire(int fd) {
 
 int terminal_set_keyboard(int fd, bool enable) {
 	log_debugf("Setting KD keyboard state to %d", enable);
+#ifndef __NetBSD__
 	if (ioctl(fd, KDSKBMODE, enable ? K_ENABLE : K_DISABLE) == -1) {
 		log_errorf("Could not set KD keyboard mode to %s: %s",
 			   enable ? "enabled" : "disabled", strerror(errno));
 		return -1;
 	}
+#else
+	int mode = enable ? WSKBD_RAW : WSKBD_TRANSLATED;
+	if (ioctl(fd, WSKBDIO_SETMODE, &mode) == -1) {
+		log_errorf("Could not set keyboard mode to %s: %s",
+			   enable ? "translated" : "raw", strerror(errno));
+		return -1;
+	}
+#endif
 #if defined(__FreeBSD__)
 	struct termios tios;
 	if (tcgetattr(fd, &tios) == -1) {
@@ -269,10 +291,19 @@ int terminal_set_keyboard(int fd, bool e
 
 int terminal_set_graphics(int fd, bool enable) {
 	log_debugf("Setting KD graphics state to %d", enable);
+#ifndef __NetBSD__
 	if (ioctl(fd, KDSETMODE, enable ? KD_GRAPHICS : KD_TEXT) == -1) {
 		log_errorf("Could not set KD graphics mode to %s: %s", enable ? "graphics" : "text",
 			   strerror(errno));
 		return -1;
 	}
+#else
+	int mode = enable ? WSDISPLAYIO_MODE_MAPPED : WSDISPLAYIO_MODE_EMUL;
+	if (ioctl(fd, WSDISPLAYIO_SMODE, &mode) == -1) {
+		log_errorf("Could not set graphics mode to %s: %s", enable ? "mapped" : "emul",
+			   strerror(errno));
+		return -1;
+	}
+#endif
 	return 0;
 }
