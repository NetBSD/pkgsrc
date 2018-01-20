$NetBSD: patch-src_runtime_mgc0.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change PhysPageSize to variable

--- src/runtime/mgc0.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/mgc0.c
@@ -330,7 +330,11 @@ scanblock(byte *b, uintptr n, byte *ptrm
 			if(obj == nil)
 				continue;
 			if(obj < arena_start || obj >= arena_used) {
+#ifndef GOOS_netbsd
 				if((uintptr)obj < PhysPageSize && runtime·invalidptr) {
+#else
+				if((uintptr)obj < runtime·physpagesz && runtime·invalidptr) {
+#endif
 					s = nil;
 					goto badobj;
 				}
@@ -1893,7 +1897,11 @@ runtime·MHeap_MapBits(MHeap *h)
 
 	n = (h->arena_used - h->arena_start) / (PtrSize*wordsPerBitmapByte);
 	n = ROUND(n, bitmapChunk);
+#ifndef GOOS_netbsd
 	n = ROUND(n, PhysPageSize);
+#else
+	n = ROUND(n, runtime·physpagesz);
+#endif
 	if(h->bitmap_mapped >= n)
 		return;
 
