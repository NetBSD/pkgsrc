$NetBSD: patch-lib_fflush.c,v 1.3 2019/01/10 06:47:42 gutteridge Exp $

Address seek function API change from circa NetBSD 6, originally
reported as PR pkg/47914.

--- lib/fflush.c.orig	2018-06-25 04:09:24.000000000 +0000
+++ lib/fflush.c
@@ -101,7 +101,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
 {
 #  if defined __sferror || defined __DragonFly__ || defined __ANDROID__
   /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin, Minix 3, Android */
-#   if defined __CYGWIN__
+#   if defined __CYGWIN__ || (defined __NetBSD__ && __NetBSD_Version__ >= 600000000) || defined __minix
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
