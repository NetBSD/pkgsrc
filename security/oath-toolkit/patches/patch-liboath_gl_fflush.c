$NetBSD: patch-liboath_gl_fflush.c,v 1.3 2013/03/16 20:52:38 pettai Exp $

--- liboath/gl/fflush.c.orig	2013-01-03 22:33:04.000000000 +0000
+++ liboath/gl/fflush.c
@@ -96,7 +96,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #  if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
