$NetBSD: patch-lib-fseeko.c,v 1.1 2012/03/06 23:38:04 joerg Exp $

--- lib/fseeko.c.orig	2011-08-12 08:05:46.000000000 +0000
+++ lib/fseeko.c
@@ -111,7 +111,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
