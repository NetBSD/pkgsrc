$NetBSD: patch-serial.c,v 1.2 2019/05/01 20:22:02 gdt Exp $

Need cfmakeraw on SunOS.

--- serial.c.orig	2018-09-22 23:24:39.000000000 +0000
+++ serial.c
@@ -173,7 +173,7 @@ void gpsd_tty_init(struct gps_device_t *
     session->reawake = (time_t)0;
 }
 
-#if defined(__CYGWIN__)
+#if defined(__CYGWIN__) || defined(__sun)
 /* Workaround for Cygwin, which is missing cfmakeraw */
 /* Pasted from man page; added in serial.c arbitrarily */
 void cfmakeraw(struct termios *termios_p)
