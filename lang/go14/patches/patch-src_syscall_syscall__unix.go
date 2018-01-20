$NetBSD: patch-src_syscall_syscall__unix.go,v 1.1 2018/01/20 16:55:25 christos Exp $

--- src/syscall/syscall_unix.go.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/syscall/syscall_unix.go
@@ -22,6 +22,7 @@ const (
 	darwin64Bit    = runtime.GOOS == "darwin" && sizeofPtr == 8
 	dragonfly64Bit = runtime.GOOS == "dragonfly" && sizeofPtr == 8
 	netbsd32Bit    = runtime.GOOS == "netbsd" && sizeofPtr == 4
+	netbsd32BitArm = runtime.GOOS == "netbsd" && runtime.GOOS == "arm"
 )
 
 func Syscall(trap, a1, a2, a3 uintptr) (r1, r2 uintptr, err Errno)
