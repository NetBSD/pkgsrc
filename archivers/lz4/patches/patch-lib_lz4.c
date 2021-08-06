$NetBSD: patch-lib_lz4.c,v 1.1 2021/08/06 05:08:50 kim Exp $

Fix potential memory corruption with negative memmove() size
Ref: https://github.com/lz4/lz4/pull/972

Addresses CVE-2021-3520

https://github.com/lz4/lz4/commit/7a966c1511816b53ac93aa2f2a2ff97e036a4a60.patch

--- lib/lz4.c
+++ lib/lz4.c
@@ -1749,7 +1749,7 @@ LZ4_decompress_generic(
                  const size_t dictSize         /* note : = 0 if noDict */
                  )
 {
-    if (src == NULL) { return -1; }
+    if ((src == NULL) || (outputSize < 0)) { return -1; }
 
     {   const BYTE* ip = (const BYTE*) src;
         const BYTE* const iend = ip + srcSize;
