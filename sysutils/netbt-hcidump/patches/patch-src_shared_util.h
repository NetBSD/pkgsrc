$NetBSD: patch-src_shared_util.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

Linux vs BSD incompatibilities

--- src/shared/util.h.orig	2014-12-12 13:38:33.000000000 +0000
+++ src/shared/util.h
@@ -23,8 +23,7 @@
 
 #include <stdint.h>
 #include <stdlib.h>
-#include <alloca.h>
-#include <byteswap.h>
+#include <machine/bswap.h>
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define le16_to_cpu(val) (val)
