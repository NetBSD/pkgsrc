$NetBSD: patch-src_runtime_mem__bsd.go,v 1.2 2017/05/19 18:50:41 fhajny Exp $

runtime: mmap(2) on Solaris & Illumos can return EAGAIN
https://github.com/golang/go/commit/13cdd814ea0e8ef165ab54802f9f102b8b690df7

This patch should be removed when we update to 1.9.

--- src/runtime/mem_bsd.go.orig	2017-04-07 16:54:08.000000000 +0000
+++ src/runtime/mem_bsd.go
@@ -59,6 +59,7 @@ func sysReserve(v unsafe.Pointer, n uint
 	return p
 }
 
+const _sunosEAGAIN = 11
 const _ENOMEM = 12
 
 func sysMap(v unsafe.Pointer, n uintptr, reserved bool, sysStat *uint64) {
@@ -76,7 +77,7 @@ func sysMap(v unsafe.Pointer, n uintptr,
 			flags |= _MAP_FIXED
 		}
 		p := mmap(v, n, _PROT_READ|_PROT_WRITE, flags, -1, 0)
-		if uintptr(p) == _ENOMEM {
+		if uintptr(p) == _ENOMEM || (GOOS == "solaris" && uintptr(p) == _sunosEAGAIN) {
 			throw("runtime: out of memory")
 		}
 		if p != v {
@@ -87,7 +88,7 @@ func sysMap(v unsafe.Pointer, n uintptr,
 	}
 
 	p := mmap(v, n, _PROT_READ|_PROT_WRITE, _MAP_ANON|_MAP_FIXED|_MAP_PRIVATE, -1, 0)
-	if uintptr(p) == _ENOMEM {
+	if uintptr(p) == _ENOMEM || (GOOS == "solaris" && uintptr(p) == _sunosEAGAIN) {
 		throw("runtime: out of memory")
 	}
 	if p != v {
