$NetBSD: patch-libxl_libxl__save__helper.c,v 1.1 2015/10/19 16:40:41 joerg Exp $

Avoid format string warnings.

--- libxl/libxl_save_helper.c.orig	2015-10-09 22:56:13.000000000 +0000
+++ libxl/libxl_save_helper.c
@@ -92,6 +92,7 @@ typedef struct {
     xentoollog_logger vtable;
 } xentoollog_logger_tellparent;
 
+__attribute__((__format__(__printf__, 5, 0)))
 static void tellparent_vmessage(xentoollog_logger *logger_in,
                                 xentoollog_level level,
                                 int errnoval,
