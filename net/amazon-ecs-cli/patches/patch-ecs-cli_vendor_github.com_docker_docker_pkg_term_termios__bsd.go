$NetBSD: patch-ecs-cli_vendor_github.com_docker_docker_pkg_term_termios__bsd.go,v 1.1 2020/09/12 14:53:39 leot Exp $

Add support for NetBSD.

--- ecs-cli/vendor/github.com/docker/docker/pkg/term/termios_bsd.go.orig	2020-07-07 22:09:30.000000000 +0000
+++ ecs-cli/vendor/github.com/docker/docker/pkg/term/termios_bsd.go
@@ -1,4 +1,4 @@
-// +build darwin freebsd openbsd
+// +build darwin freebsd netbsd openbsd
 
 package term // import "github.com/docker/docker/pkg/term"
 
