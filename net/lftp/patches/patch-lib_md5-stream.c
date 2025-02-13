$NetBSD: patch-lib_md5-stream.c,v 1.1 2025/02/13 09:10:43 adam Exp $

Avoid duplicate symbols.
https://github.com/lavv17/lftp/issues/743

--- lib/md5-stream.c.orig	2025-02-13 07:48:10.019120268 +0000
+++ lib/md5-stream.c
@@ -22,9 +22,6 @@
 #include <config.h>
 
 /* Specification.  */
-#if HAVE_OPENSSL_MD5
-# define GL_OPENSSL_INLINE _GL_EXTERN_INLINE
-#endif
 #include "md5.h"
 
 #include <stdlib.h>
