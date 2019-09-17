$NetBSD: patch-vendor_github.com_spacemonkeygo_spacelog_capture__other.go,v 1.1 2019/09/17 08:21:01 adam Exp $

Use unix.Dup2 instead of syscall.Dup2.

--- vendor/github.com/spacemonkeygo/spacelog/capture_other.go.orig	2016-12-29 22:33:41.000000000 +0000
+++ vendor/github.com/spacemonkeygo/spacelog/capture_other.go
@@ -17,17 +17,18 @@
 package spacelog
 
 import (
+	"golang.org/x/sys/unix"
 	"syscall"
 )
 
 // CaptureOutputToFd redirects the current process' stdout and stderr file
 // descriptors to the given file descriptor, using the dup2 syscall.
 func CaptureOutputToFd(fd int) error {
-	err := syscall.Dup2(fd, syscall.Stdout)
+	err := unix.Dup2(fd, syscall.Stdout)
 	if err != nil {
 		return err
 	}
-	err = syscall.Dup2(fd, syscall.Stderr)
+	err = unix.Dup2(fd, syscall.Stderr)
 	if err != nil {
 		return err
 	}
