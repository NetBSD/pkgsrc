$NetBSD: patch-liboath_gl_fflush.c,v 1.2 2012/11/10 18:07:44 pettai Exp $

--- liboath/gl/fflush.c.orig	2012-08-07 07:13:22.000000000 +0000
+++ liboath/gl/fflush.c
@@ -94,7 +94,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
