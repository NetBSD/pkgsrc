$NetBSD: patch-vendor_github.com_ory_dockertest_docker_pkg_term_term.go,v 1.1 2019/10/23 15:00:05 he Exp $

Use syscall.Termios and import "syscall", so that this builds on NetBSD.

--- vendor/github.com/ory/dockertest/docker/pkg/term/term.go.orig	2019-09-09 21:08:25.000000000 +0000
+++ vendor/github.com/ory/dockertest/docker/pkg/term/term.go
@@ -10,6 +10,7 @@ import (
 	"io"
 	"os"
 	"os/signal"
+	"syscall"
 
 	"golang.org/x/sys/unix"
 )
@@ -21,7 +22,7 @@ var (
 
 // State represents the state of the terminal.
 type State struct {
-	termios Termios
+	termios syscall.Termios
 }
 
 // Winsize represents the size of the terminal window.
@@ -50,7 +51,7 @@ func GetFdInfo(in interface{}) (uintptr,
 
 // IsTerminal returns true if the given file descriptor is a terminal.
 func IsTerminal(fd uintptr) bool {
-	var termios Termios
+	var termios syscall.Termios
 	return tcget(fd, &termios) == 0
 }
 
