$NetBSD: patch-serial.c,v 1.1 2013/12/10 12:22:52 jperkin Exp $

Need cfmakeraw on SunOS.

--- serial.c.orig	2011-03-15 03:34:32.000000000 +0000
+++ serial.c
@@ -125,7 +125,7 @@ void gpsd_tty_init(struct gps_device_t *
     session->reawake = (timestamp_t)0;
 }
 
-#if defined(__CYGWIN__)
+#if defined(__CYGWIN__) || defined(__sun)
 /* Workaround for Cygwin, which is missing cfmakeraw */
 /* Pasted from man page; added in serial.c arbitrarily */
 void cfmakeraw(struct termios *termios_p)
