$NetBSD: patch-vendor_github.com_ory_dockertest_docker_pkg_term_tc.go,v 1.1 2019/10/23 15:00:05 he Exp $

Use syscall.Termios, not just Termios, so that this builds on at
least NetBSD.

--- vendor/github.com/ory/dockertest/docker/pkg/term/tc.go.orig	2019-09-09 21:08:25.000000000 +0000
+++ vendor/github.com/ory/dockertest/docker/pkg/term/tc.go
@@ -9,12 +9,12 @@ import (
 	"golang.org/x/sys/unix"
 )
 
-func tcget(fd uintptr, p *Termios) syscall.Errno {
+func tcget(fd uintptr, p *syscall.Termios) syscall.Errno {
 	_, _, err := unix.Syscall(unix.SYS_IOCTL, fd, uintptr(getTermios), uintptr(unsafe.Pointer(p)))
 	return err
 }
 
-func tcset(fd uintptr, p *Termios) syscall.Errno {
+func tcset(fd uintptr, p *syscall.Termios) syscall.Errno {
 	_, _, err := unix.Syscall(unix.SYS_IOCTL, fd, setTermios, uintptr(unsafe.Pointer(p)))
 	return err
 }
