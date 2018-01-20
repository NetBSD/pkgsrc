$NetBSD: patch-src_runtime_runtime.h,v 1.1 2018/01/20 16:55:25 christos Exp $

  * Add extern for physpagesz

--- src/runtime/runtime.h.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/runtime.h
@@ -765,6 +765,9 @@ extern	Note	runtime·signote;
 extern	ForceGCState	runtime·forcegc;
 extern	SchedT	runtime·sched;
 extern	int32		runtime·newprocs;
+#ifdef GOOS_netbsd
+extern	uintptr		runtime·physpagesz;
+#endif
 
 /*
  * common functions and data
