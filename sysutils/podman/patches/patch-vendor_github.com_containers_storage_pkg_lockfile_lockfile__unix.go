$NetBSD: patch-vendor_github.com_containers_storage_pkg_lockfile_lockfile__unix.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support (vendor code)
For some reason unix.SEEK_SET is not defined in the NetBSD runtime code.
But SEEK_SET is 0 on every platform, so just use that for now.

--- vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || solaris || darwin || freebsd
-// +build linux solaris darwin freebsd
+//go:build linux || solaris || darwin || freebsd || netbsd
+// +build linux solaris darwin freebsd netbsd
 
 package lockfile
 
@@ -187,7 +187,7 @@ func createLockFileForPath(path string, 
 func (l *LockFile) lock(lType int16) {
 	lk := unix.Flock_t{
 		Type:   lType,
-		Whence: int16(unix.SEEK_SET),
+		Whence: int16(0),
 		Start:  0,
 		Len:    0,
 	}
