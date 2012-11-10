$NetBSD: patch-liboath_gl_fseeko.c,v 1.2 2012/11/10 18:07:44 pettai Exp $

--- liboath/gl/fseeko.c.orig	2012-08-07 07:13:22.000000000 +0000
+++ liboath/gl/fseeko.c
@@ -119,7 +119,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
