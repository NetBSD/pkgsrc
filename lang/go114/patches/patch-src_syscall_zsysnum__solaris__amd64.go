$NetBSD: patch-src_syscall_zsysnum__solaris__amd64.go,v 1.1 2020/02/27 14:32:57 bsiegert Exp $

SunOS does have SYS_ioctl.

--- src/syscall/zsysnum_solaris_amd64.go.orig	2018-08-24 19:33:36.000000000 +0000
+++ src/syscall/zsysnum_solaris_amd64.go
@@ -8,6 +8,7 @@ package syscall
 
 // TODO(aram): remove these before Go 1.3.
 const (
+	SYS_IOCTL  = 54
 	SYS_EXECVE = 59
 	SYS_FCNTL  = 62
 )
