$NetBSD: patch-liboath_gl_fflush.c,v 1.1.2.2 2012/04/07 20:59:51 spz Exp $

--- liboath/gl/fflush.c.orig	2012-01-03 19:18:22.000000000 +0000
+++ liboath/gl/fflush.c
@@ -91,7 +91,7 @@ static inline void
 update_fpos_cache (FILE *fp, off_t pos)
 {
 #if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
