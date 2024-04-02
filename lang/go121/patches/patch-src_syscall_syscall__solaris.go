$NetBSD: patch-src_syscall_syscall__solaris.go,v 1.1 2024/04/02 13:21:43 jperkin Exp $

Implement syscall.Mkfifo().

--- src/syscall/syscall_solaris.go.orig	2024-04-02 09:32:01.070235927 +0000
+++ src/syscall/syscall_solaris.go
@@ -279,6 +279,10 @@ func Wait4(pid int, wstatus *WaitStatus,
 	return int(r0), err
 }
 
+func Mkfifo(path string, mode uint32) (err error) {
+	return Mknod(path, mode|S_IFIFO, 0)
+}
+
 func gethostname() (name string, err uintptr)
 
 func Gethostname() (name string, err error) {
