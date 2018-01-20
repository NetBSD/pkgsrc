$NetBSD: patch-src_runtime_mheap.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * Change PhysPageSize to variable.

--- src/runtime/mheap.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/mheap.c
@@ -82,7 +82,11 @@ runtime·MHeap_MapSpans(MHeap *h)
 	n = (uintptr)h->arena_used;
 	n -= (uintptr)h->arena_start;
 	n = n / PageSize * sizeof(h->spans[0]);
+#ifndef GOOS_netbsd
 	n = ROUND(n, PhysPageSize);
+#else
+	n = ROUND(n, runtime·physpagesz);
+#endif
 	if(h->spans_mapped >= n)
 		return;
 	runtime·SysMap((byte*)h->spans + h->spans_mapped, n - h->spans_mapped, h->arena_reserved, &mstats.other_sys);
