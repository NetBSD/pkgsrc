$NetBSD: patch-liboath_gl_fflush.c,v 1.4 2022/08/22 07:42:52 sborrill Exp $

Fix build on NetBSD

--- liboath/gl/fflush.c.orig	2021-01-20 12:13:56.000000000 +0000
+++ liboath/gl/fflush.c	2022-08-17 10:41:26.973082601 +0100
@@ -101,7 +101,7 @@
 {
 #  if defined __sferror || defined __DragonFly__ || defined __ANDROID__
   /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Minix 3, Android */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
