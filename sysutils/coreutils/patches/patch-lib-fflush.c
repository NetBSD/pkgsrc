$NetBSD: patch-lib-fflush.c,v 1.2 2014/02/02 07:08:25 richard Exp $

--- lib/fflush.c.orig	2013-12-04 14:53:33.000000000 +0000
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
