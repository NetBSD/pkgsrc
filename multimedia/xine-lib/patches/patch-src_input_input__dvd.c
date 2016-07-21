$NetBSD: patch-src_input_input__dvd.c,v 1.1 2016/07/21 12:21:36 wiz Exp $

Environment variable fix for libdvdcss 1.4.0 and later.

--- src/input/input_dvd.c.orig	2016-07-19 20:02:16.000000000 +0000
+++ src/input/input_dvd.c
@@ -1401,7 +1401,11 @@ static int dvd_parse_try_open(dvd_input_
     /* we have an alternative dvd_path */
     intended_dvd_device = locator;
     /* do not use the raw device for the alternative */
+#if 1	 /* libdvdcss version 1.4.0 or later */
+    unsetenv("DVDCSS_RAW_DEVICE");
+#else
     xine_setenv("DVDCSS_RAW_DEVICE", "", 1);
+#endif
   } else {
     /* use default DVD device */
     dvd_input_class_t *class = (dvd_input_class_t*)this->input_plugin.input_class;
