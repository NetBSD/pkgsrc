$NetBSD: patch-src_runtime_stack.c,v 1.1 2019/04/13 23:09:40 maya Exp $

OpenBSD 6.4 needs stack pages to be mapped with MAP_STACK.

--- src/runtime/stack.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/stack.c
@@ -67,6 +67,9 @@ poolalloc(uint8 order)
 		s = runtime·MHeap_AllocStack(&runtime·mheap, StackCacheSize >> PageShift);
 		if(s == nil)
 			runtime·throw("out of memory");
+#ifdef GOOS_openbsd
+		runtime·sysMarkStack((void *)(s->start << PageShift), s->npages << PageShift);
+#endif
 		if(s->ref != 0)
 			runtime·throw("bad ref");
 		if(s->freelist != nil)
@@ -246,6 +249,9 @@ runtime·stackalloc(uint32 n)
 		s = runtime·MHeap_AllocStack(&runtime·mheap, ROUND(n, PageSize) >> PageShift);
 		if(s == nil)
 			runtime·throw("out of memory");
+#ifdef GOOS_openbsd
+		runtime·sysMarkStack((void *)(s->start << PageShift), s->npages << PageShift);
+#endif
 		v = (byte*)(s->start<<PageShift);
 	}
 	
