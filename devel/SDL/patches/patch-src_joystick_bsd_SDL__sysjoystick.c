$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.1 2014/03/24 20:29:01 asau Exp $

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
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
