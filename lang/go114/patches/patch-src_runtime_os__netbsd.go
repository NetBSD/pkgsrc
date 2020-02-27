$NetBSD: patch-src_runtime_os__netbsd.go,v 1.1 2020/02/27 14:32:57 bsiegert Exp $

--- src/runtime/os_netbsd.go.orig	2017-02-16 19:12:24.000000000 +0000
+++ src/runtime/os_netbsd.go
@@ -79,13 +79,13 @@ var sigset_all = sigset{[4]uint32{^uint3
 
 // From NetBSD's <sys/sysctl.h>
 const (
-	_CTL_HW      = 6
-	_HW_NCPU     = 3
+	_CTL_HW  = 6
+	_HW_NCPUONLINE = 16
 	_HW_PAGESIZE = 7
 )
 
 func getncpu() int32 {
-	mib := [2]uint32{_CTL_HW, _HW_NCPU}
+	mib := [2]uint32{_CTL_HW, _HW_NCPUONLINE}
 	out := uint32(0)
 	nout := unsafe.Sizeof(out)
 	ret := sysctl(&mib[0], 2, (*byte)(unsafe.Pointer(&out)), &nout, nil, 0)
