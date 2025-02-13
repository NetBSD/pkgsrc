$NetBSD: patch-lib_sha1-stream.c,v 1.1 2025/02/13 09:10:43 adam Exp $

Avoid duplicate symbols.
https://github.com/lavv17/lftp/issues/743

--- lib/sha1-stream.c.orig	2025-02-13 07:48:47.519257029 +0000
+++ lib/sha1-stream.c
@@ -24,9 +24,6 @@
 #include <config.h>
 
 /* Specification.  */
-#if HAVE_OPENSSL_SHA1
-# define GL_OPENSSL_INLINE _GL_EXTERN_INLINE
-#endif
 #include "sha1.h"
 
 #include <stdlib.h>
