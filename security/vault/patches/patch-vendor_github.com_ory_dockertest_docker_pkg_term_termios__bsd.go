$NetBSD: patch-vendor_github.com_ory_dockertest_docker_pkg_term_termios__bsd.go,v 1.1 2019/10/23 15:00:05 he Exp $

Build this on NetBSD as well.

--- vendor/github.com/ory/dockertest/docker/pkg/term/termios_bsd.go.orig	2019-09-09 21:08:25.000000000 +0000
+++ vendor/github.com/ory/dockertest/docker/pkg/term/termios_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd openbsd
+// +build darwin freebsd openbsd netbsd
 
 package term // import "github.com/ory/dockertest/docker/pkg/term"
 
