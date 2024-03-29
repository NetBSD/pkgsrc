$NetBSD: patch-src_is__fileio.h,v 1.2 2022/12/14 14:55:02 wiz Exp $

Add missing header file.
https://github.com/kuroneko/sais/pull/8

--- src/is_fileio.h.orig	2020-10-14 04:48:50.000000000 +0000
+++ src/is_fileio.h
@@ -22,6 +22,7 @@
 #define IS_FILEIO_H
 
 #include <physfs.h>
+#include <stdarg.h>
 
 typedef PHYSFS_File *   IS_FileHdl;
 
