$NetBSD: patch-src_third-party_ArenaAlloc_arenaallocimpl.h,v 1.1 2023/05/24 22:42:53 he Exp $

Don't try to right-shift by 32 bits on a 32-bit host.

--- ./src/third-party/ArenaAlloc/arenaallocimpl.h.orig	2022-07-29 17:43:50.000000000 +0000
+++ ./src/third-party/ArenaAlloc/arenaallocimpl.h
@@ -13,6 +13,8 @@
 #include <stdio.h>
 #endif
 
+#include <stdint.h>
+
 namespace ArenaAlloc
 {
 
@@ -108,7 +110,9 @@ namespace ArenaAlloc
       value |= value >> 4;
       value |= value >> 8;
       value |= value >> 16;
+#if SIZE_MAX > UINT32_MAX
       value |= value >> 32;
+#endif
 
       return value + 1;            
     }
