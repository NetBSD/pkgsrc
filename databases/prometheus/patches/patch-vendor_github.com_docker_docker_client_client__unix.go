$NetBSD: patch-vendor_github.com_docker_docker_client_client__unix.go,v 1.1 2021/01/28 21:45:26 jperkin Exp $

Fix SunOS.

--- vendor/github.com/docker/docker/client/client_unix.go.orig	2020-11-26 10:11:54.000000000 +0000
+++ vendor/github.com/docker/docker/client/client_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd openbsd netbsd darwin dragonfly
+// +build linux freebsd openbsd netbsd darwin dragonfly solaris
 
 package client // import "github.com/docker/docker/client"
 
