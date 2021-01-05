$NetBSD: patch-vendor_github.com_docker_docker_client_client__unix.go,v 1.2 2021/01/05 11:02:51 he Exp $

Build this also on NetBSD.

--- vendor/github.com/docker/docker/client/client_unix.go.orig	2020-11-02 20:22:40.000000000 +0000
+++ vendor/github.com/docker/docker/client/client_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd openbsd darwin
+// +build linux freebsd openbsd darwin netbsd
 
 package client // import "github.com/docker/docker/client"
 
