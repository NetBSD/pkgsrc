$NetBSD: patch-src_runtime_mem__freebsd.c,v 1.1 2026/09/13 08:38:04 bsiegert Exp $

Fix FreeBSD address space conflict when ASLR is enabled.

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235735

--- src/runtime/mem_freebsd.c.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/runtime/mem_freebsd.c
@@ -73,6 +73,11 @@ runtime·SysReserve(void *v, uintptr n,
 	return p;
 }
 
+enum
+{
+	MAP_EXCL = 0x4000
+};
+
 void
 runtime·SysMap(void *v, uintptr n, bool reserved, uint64 *stat)
 {
@@ -82,7 +87,7 @@ runtime·SysMap(void *v, uintptr n, bool
 
 	// On 64-bit, we don't actually have v reserved, so tread carefully.
 	if(!reserved) {
-		p = runtime·mmap(v, n, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
+		p = runtime·mmap(v, n, PROT_READ|PROT_WRITE, MAP_ANON|MAP_FIXED|MAP_EXCL|MAP_PRIVATE, -1, 0);
 		if(p == (void*)ENOMEM)
 			runtime·throw("runtime: out of memory");
 		if(p != v) {
