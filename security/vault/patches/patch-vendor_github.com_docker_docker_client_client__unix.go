$NetBSD: patch-vendor_github.com_docker_docker_client_client__unix.go,v 1.1 2020/09/10 22:10:59 he Exp $

Build this also on NetBSD.

--- vendor/github.com/docker/docker/client/client_unix.go.orig	2020-08-26 22:40:59.000000000 +0000
+++ vendor/github.com/docker/docker/client/client_unix.go
@@ -1,4 +1,4 @@
-// +build linux freebsd openbsd darwin solaris illumos
+// +build linux freebsd openbsd darwin solaris illumos netbsd
 
 package client // import "github.com/docker/docker/client"
 
