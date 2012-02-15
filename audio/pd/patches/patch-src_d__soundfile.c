$NetBSD: patch-src_d__soundfile.c,v 1.1 2012/02/15 22:36:39 hans Exp $

--- src/d_soundfile.c.orig	2010-08-03 05:40:14.000000000 +0200
+++ src/d_soundfile.c	2012-01-02 14:47:53.852302429 +0100
@@ -30,7 +30,11 @@ objects use Posix-like threads.  */
 #ifdef _LARGEFILE64_SOURCE
 # define open open64
 # define lseek lseek64
-#define off_t __off64_t
+# ifndef __sun
+#  define off_t __off64_t
+# else
+#  define off_t off64_t
+# endif
 #endif
 #ifdef MSW
 #define off_t long
