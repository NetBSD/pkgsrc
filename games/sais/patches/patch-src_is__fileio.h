$NetBSD: patch-src_is__fileio.h,v 1.1 2022/12/14 14:51:58 wiz Exp $

Add missing header file.

--- src/is_fileio.h.orig	2020-10-14 04:48:50.000000000 +0000
+++ src/is_fileio.h
@@ -22,6 +22,7 @@
 #define IS_FILEIO_H
 
 #include <physfs.h>
+#include <stdarg.h>
 
 typedef PHYSFS_File *   IS_FileHdl;
 
