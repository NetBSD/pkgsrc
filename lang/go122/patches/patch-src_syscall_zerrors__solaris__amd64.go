$NetBSD: patch-src_syscall_zerrors__solaris__amd64.go,v 1.2 2024/06/13 12:55:15 bsiegert Exp $

Support O_DIRECT on illumos.

--- src/syscall/zerrors_solaris_amd64.go.orig	2024-05-30 19:26:07.000000000 +0000
+++ src/syscall/zerrors_solaris_amd64.go
@@ -634,6 +634,7 @@ const (
 	O_APPEND                      = 0x8
 	O_CLOEXEC                     = 0x800000
 	O_CREAT                       = 0x100
+	O_DIRECT                      = 0x2000000
 	O_DIRECTORY                   = 0x1000000
 	O_DSYNC                       = 0x40
 	O_EXCL                        = 0x400
