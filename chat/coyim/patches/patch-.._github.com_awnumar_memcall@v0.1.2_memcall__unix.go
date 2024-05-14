$NetBSD: patch-.._github.com_awnumar_memcall@v0.1.2_memcall__unix.go,v 1.1 2024/05/14 22:38:57 wiz Exp $

Add NetBSD support.
https://github.com/awnumar/memcall/pull/10

--- ../github.com/awnumar/memcall@v0.1.2/memcall_unix.go.orig	1979-11-29 23:00:00.000000000 +0000
+++ ../github.com/awnumar/memcall@v0.1.2/memcall_unix.go
@@ -1,4 +1,4 @@
-// +build !windows,!darwin,!openbsd,!freebsd
+// +build !windows,!darwin,!openbsd,!freebsd,!netbsd
 
 package memcall
 
