$NetBSD: patch-src_syscall_sockcmsg__unix.go,v 1.1 2019/03/09 09:29:30 bsiegert Exp $

Fix alignment of socket control messages on NetBSD/arm.
https://golang.org/issue/24771

--- src/syscall/sockcmsg_unix.go.orig	2019-02-25 23:05:57.000000000 +0000
+++ src/syscall/sockcmsg_unix.go
@@ -25,7 +25,7 @@ func cmsgAlignOf(salen int) int {
 		if sizeofPtr == 8 {
 			salign = 4
 		}
-	case "openbsd":
+	case "netbsd", "openbsd":
 		// OpenBSD armv7 requires 64-bit alignment.
 		if runtime.GOARCH == "arm" {
 			salign = 8
