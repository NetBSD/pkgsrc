$NetBSD: patch-src_syscall_zerrors__solaris__amd64.go,v 1.1 2024/04/09 16:57:46 jperkin Exp $

Support O_DIRECT on illumos.

--- src/syscall/zerrors_solaris_amd64.go.orig	2024-04-09 15:36:45.882494751 +0000
+++ src/syscall/zerrors_solaris_amd64.go
@@ -634,6 +634,7 @@ const (
 	O_APPEND                      = 0x8
 	O_CLOEXEC                     = 0x800000
 	O_CREAT                       = 0x100
+	O_DIRECT                      = 0x2000000
 	O_DSYNC                       = 0x40
 	O_EXCL                        = 0x400
 	O_EXEC                        = 0x400000
