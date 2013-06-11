$NetBSD: patch-lib_fflush.c,v 1.2 2013/06/11 08:28:30 adam Exp $

--- lib/fflush.c.orig	2013-06-09 20:37:56.000000000 +0000
+++ lib/fflush.c
@@ -96,7 +96,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #  if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
