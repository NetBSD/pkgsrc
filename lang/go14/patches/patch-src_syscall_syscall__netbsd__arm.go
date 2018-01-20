$NetBSD: patch-src_syscall_syscall__netbsd__arm.go,v 1.1 2018/01/20 16:55:25 christos Exp $

 * 

--- src/syscall/syscall_netbsd_arm.go.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/syscall/syscall_netbsd_arm.go
@@ -4,7 +4,9 @@
 
 package syscall
 
-func Getpagesize() int { return 4096 }
+import "runtime"
+
+func Getpagesize() int { return runtime.Physpagesize() }
 
 func TimespecToNsec(ts Timespec) int64 { return int64(ts.Sec)*1e9 + int64(ts.Nsec) }
 
