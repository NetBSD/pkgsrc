$NetBSD: patch-libxl_libxl__save__helper.c,v 1.1.1.1 2016/07/04 07:30:52 jnemeth Exp $

--- libxl/libxl_save_helper.c.orig	2015-01-25 21:04:31.000000000 +0000
+++ libxl/libxl_save_helper.c
@@ -49,6 +49,7 @@
 
 /*----- logger -----*/
 
+__attribute__((__format__(__printf__, 5, 0)))
 static void tellparent_vmessage(xentoollog_logger *logger_in,
                                 xentoollog_level level,
                                 int errnoval,
