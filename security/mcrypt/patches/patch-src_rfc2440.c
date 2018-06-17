$NetBSD: patch-src_rfc2440.c,v 1.1.2.2 2018/06/17 11:40:03 spz Exp $

* Correct include file for OSX
* Minor consistency change (previously len was uninitialized)

From: Brew, Red Hat, SUSE

--- src/rfc2440.c.orig	2008-11-16 19:50:01.000000000 +0000
+++ src/rfc2440.c
@@ -23,7 +23,11 @@
 #include <zlib.h>
 #endif
 #include <stdio.h>
+#ifdef __APPLE__
+#include <malloc/malloc.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "xmalloc.h"
 #include "keys.h"
@@ -409,7 +413,7 @@ length_decode(const uchar *buf, int pos,
         len += (buf[pos+1] + 192);
     }
     else if (buf[pos] == 255) {
-        len += (buf[pos+1] << 24);
+        len = (buf[pos+1] << 24);
         len += (buf[pos+2] << 16);
         len += (buf[pos+3] << 8);
         len += buf[pos+4];
