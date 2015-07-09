$NetBSD: patch-md5.h,v 1.1 2015/07/09 12:07:39 jperkin Exp $

Use nbcompat.

--- md5.h.orig	2002-05-09 15:34:35.000000000 +0000
+++ md5.h
@@ -33,7 +33,12 @@ typedef struct MD5Context {
   unsigned char buffer[64];	/* input buffer */
 } MD5_CTX;
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 
 __BEGIN_DECLS
 void   MD5Init (MD5_CTX *);
