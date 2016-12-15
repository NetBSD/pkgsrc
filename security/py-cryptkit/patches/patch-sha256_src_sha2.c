$NetBSD: patch-sha256_src_sha2.c,v 1.1 2016/12/15 01:07:30 wiedi Exp $

need endian.h on SunOS for BYTE_ORDER

--- sha256/src/sha2.c.orig	2001-11-29 15:56:49.000000000 +0000
+++ sha256/src/sha2.c
@@ -36,6 +36,9 @@
  *
  */
 
+#if defined(__sun)
+#include <endian.h>
+#endif
 
 #include <string.h>	/* memcpy()/memset() or bcopy()/bzero() */
 #include <assert.h>	/* assert() */
