$NetBSD: patch-vendor_src_github.com_spacemonkeygo_spacelog_capture__other.go,v 1.1 2017/05/03 16:49:54 fhajny Exp $

Use unix.Dup2 instead of syscall.Dup2.

--- vendor/src/github.com/spacemonkeygo/spacelog/capture_other.go.orig	2016-12-29 22:33:41.000000000 +0000
+++ vendor/src/github.com/spacemonkeygo/spacelog/capture_other.go
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
