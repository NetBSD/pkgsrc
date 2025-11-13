$NetBSD: patch-filetype_file-gcc_config.h,v 1.1 2025/11/13 22:28:17 wiz Exp $

NetBSD does not have uselocale().

--- filetype/file-gcc/config.h.orig	2025-11-13 22:15:18.574915697 +0000
+++ filetype/file-gcc/config.h
@@ -247,7 +247,7 @@
 #define HAVE_UNISTD_H 1
 
 /* Define to 1 if you have the `uselocale' function. */
-#define HAVE_USELOCALE 1
+/*#define HAVE_USELOCALE 1 */
 
 /* Define to 1 if you have the `utime' function. */
 #define HAVE_UTIME 1
