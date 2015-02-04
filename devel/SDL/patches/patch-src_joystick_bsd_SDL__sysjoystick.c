$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.2 2015/02/04 23:51:26 jmcneill Exp $

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -77,7 +77,7 @@
 #include "../SDL_sysjoystick.h"
 #include "../SDL_joystick_c.h"
 
-#define MAX_UHID_JOYS	4
+#define MAX_UHID_JOYS	64
 #define MAX_JOY_JOYS	2
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
@@ -148,9 +148,11 @@ static char *joydevnames[MAX_JOYS];
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#if defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) && (__FreeBSD_kernel_version >= 900000)
+#define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
+#elif defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
-#elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063))
+#elif (defined(__FreeBSD__) && (__FreeBSD_kernel_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
 #else
 #define REP_BUF_DATA(rep) ((rep)->buf->data)
@@ -386,6 +388,11 @@ SDL_SYS_JoystickOpen(SDL_Joystick *joy)
 		if (hw->axis_map[i] > 0)
 			hw->axis_map[i] = joy->naxes++;
 
+	if (joy->naxes == 0 && joy->nbuttons == 0 && joy->nhats == 0 && joy->nballs == 0) {
+		SDL_SetError("%s: Not a joystick, ignoring", hw->path);
+		goto usberr;
+	}
+
 usbend:
 	/* The poll blocks the event thread. */
 	fcntl(fd, F_SETFL, O_NONBLOCK);
