$NetBSD: patch-lib-fseeko.c,v 1.2 2014/02/02 07:08:25 richard Exp $

--- lib/fseeko.c.orig	2013-12-04 15:02:00.000000000 +0000
+++ lib/fseeko.c
@@ -125,7 +125,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
