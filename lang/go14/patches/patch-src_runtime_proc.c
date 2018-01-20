$NetBSD: patch-src_runtime_proc.c,v 1.1 2018/01/20 16:55:25 christos Exp $

 * add physpagesz variable when netbsd

--- src/runtime/proc.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/proc.c
@@ -44,6 +44,9 @@ P*	runtime·allp[MaxGomaxprocs+1];
 int8*	runtime·goos;
 int32	runtime·ncpu;
 int32	runtime·newprocs;
+#ifdef GOOS_netbsd
+uintptr	runtime·physpagesz;
+#endif
 
 Mutex runtime·allglock;	// the following vars are protected by this lock or by stoptheworld
 G**	runtime·allg;
