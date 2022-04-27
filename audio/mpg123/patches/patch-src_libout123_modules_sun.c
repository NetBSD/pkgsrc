$NetBSD: patch-src_libout123_modules_sun.c,v 1.1 2022/04/27 21:15:23 nia Exp $

Disable legacy code for fiddling with mixer parameters like volume
and output port.  This is not really something we want done on
modern Solaris on NetBSD where the device is abstracted, and
setting the port can fail loudly on some hardware like
Raspberry Pis.

--- src/libout123/modules/sun.c.orig	2021-12-10 07:00:58.000000000 +0000
+++ src/libout123/modules/sun.c
@@ -174,7 +174,8 @@ static int open_sun(out123_handle *ao)
 #endif
 	
 	if(reset_parameters_sun(ao) < 0) return -1;
-	
+
+#if 0	
 	AUDIO_INITINFO(&ainfo);
 	
 	if(ao->flags > 0)
@@ -193,6 +194,7 @@ static int open_sun(out123_handle *ao)
 	
 	if(ioctl(ao->fn, AUDIO_SETINFO, &ainfo) == -1)
 		return -1;
+#endif
 	
 	return ao->fn;
 }
