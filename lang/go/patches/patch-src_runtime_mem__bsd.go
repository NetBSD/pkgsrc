$NetBSD: patch-src_runtime_mem__bsd.go,v 1.1.2.2 2017/05/06 15:19:40 bsiegert Exp $

Improve handling of low-memory situations on Illumos.
https://github.com/joyent/pkgsrc/pull/493

--- src/runtime/mem_bsd.go.orig	2017-04-28 12:14:22.000000000 -0700
+++ src/runtime/mem_bsd.go	2017-04-28 12:14:31.000000000 -0700
@@ -76,7 +76,7 @@
 			flags |= _MAP_FIXED
 		}
 		p := mmap(v, n, _PROT_READ|_PROT_WRITE, flags, -1, 0)
-		if uintptr(p) == _ENOMEM {
+		if uintptr(p) == _ENOMEM || (GOOS == "solaris" && uintptr(p) == _EAGAIN) {
 			throw("runtime: out of memory")
 		}
 		if p != v {
@@ -87,7 +87,7 @@
 	}
 
 	p := mmap(v, n, _PROT_READ|_PROT_WRITE, _MAP_ANON|_MAP_FIXED|_MAP_PRIVATE, -1, 0)
-	if uintptr(p) == _ENOMEM {
+	if uintptr(p) == _ENOMEM || (GOOS == "solaris" && uintptr(p) == _EAGAIN) {
 		throw("runtime: out of memory")
 	}
 	if p != v {
