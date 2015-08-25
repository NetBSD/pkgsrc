$NetBSD: patch-src_syscall_syscall__solaris.go,v 1.1 2015/08/25 23:09:51 fhajny Exp $

Add support for the Dup2 syscall.

--- src/syscall/syscall_solaris.go.orig	2015-08-19 06:05:19.000000000 +0000
+++ src/syscall/syscall_solaris.go
@@ -440,6 +440,7 @@ func SendmsgN(fd int, p, oob []byte, to
 //sys	Chroot(path string) (err error)
 //sys	Close(fd int) (err error)
 //sys	Dup(fd int) (nfd int, err error)
+//sys	Dup2(from int, to int) (err error)
 //sys	Exit(code int)
 //sys	Fchdir(fd int) (err error)
 //sys	Fchmod(fd int, mode uint32) (err error)
