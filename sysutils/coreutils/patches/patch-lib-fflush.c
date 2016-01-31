$NetBSD: patch-lib-fflush.c,v 1.3 2016/01/31 09:20:51 ryoon Exp $

--- lib/fflush.c.orig	2016-01-01 13:45:55.000000000 +0000
+++ lib/fflush.c
@@ -99,7 +99,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
 {
 #  if defined __sferror || defined __DragonFly__ || defined __ANDROID__
   /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Android */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
