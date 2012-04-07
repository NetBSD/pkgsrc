$NetBSD: patch-liboath_gl_fseeko.c,v 1.1.2.2 2012/04/07 20:59:51 spz Exp $

--- liboath/gl/fseeko.c.orig	2012-01-03 19:18:22.000000000 +0000
+++ liboath/gl/fseeko.c
@@ -109,7 +109,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
