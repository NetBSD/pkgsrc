$NetBSD: patch-lib_fflush.c,v 1.2 2019/12/15 11:49:28 mef Exp $

Add NetBSD support

--- lib/fflush.c.orig	2018-05-09 07:57:42.000000000 +0000
+++ lib/fflush.c
@@ -99,7 +99,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
 {
 #  if defined __sferror || defined __DragonFly__ || defined __ANDROID__
   /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Minix 3, Android */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
