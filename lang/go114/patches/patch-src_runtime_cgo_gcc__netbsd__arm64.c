$NetBSD: patch-src_runtime_cgo_gcc__netbsd__arm64.c,v 1.1 2020/05/01 15:58:00 tnn Exp $

provide declaration of crosscall1

--- src/runtime/cgo/gcc_netbsd_arm64.c.orig	2020-04-08 19:15:51.000000000 +0000
+++ src/runtime/cgo/gcc_netbsd_arm64.c
@@ -53,6 +53,8 @@ _cgo_sys_thread_start(ThreadStart *ts)
 	}
 }
 
+extern void crosscall1(void (*fn)(void), void (*setg_gcc)(void*), void *g);
+
 static void*
 threadentry(void *v)
 {
