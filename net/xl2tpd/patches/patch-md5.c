$NetBSD: patch-md5.c,v 1.2 2013/07/12 19:06:31 christos Exp $

Include endian.h for NetBSD
memset the right size, not just the first sizeof(ptr) bits.

--- md5.c.orig	2013-06-17 06:17:24.000000000 -0400
+++ md5.c	2013-07-12 14:52:02.000000000 -0400
@@ -7,6 +7,8 @@
 # include <endian.h>
 #elif defined(SOLARIS)
 # include <sys/isa_defs.h>
+#elif defined(NETBSD)
+# include <sys/endian.h>
 #endif
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define HIGHFIRST 1
@@ -166,7 +168,7 @@
     MD5Transform (ctx->buf, (uint32 *) ctx->in);
     byteReverse ((unsigned char *) ctx->buf, 4);
     memcpy (digest, ctx->buf, 16);
-    memset (ctx, 0, sizeof (ctx));      /* In case it's sensitive */
+    memset (ctx, 0, sizeof (*ctx));      /* In case it's sensitive */
 }
 
 #ifndef ASM_MD5
