$NetBSD: patch-vendor_github.com_containers_storage_pkg_lockfile_lockfile__unix.go,v 1.3 2024/06/03 02:07:44 maya Exp $

Add netbsd support (vendor code) - https://github.com/containers/storage/pull/1935

NOT UPSTREAMED:
For some reason unix.SEEK_SET is not defined in the NetBSD runtime code.
But SEEK_SET is 0 on every platform, so just use that for now.

--- vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go.orig	2024-05-10 15:37:14.000000000 +0000
+++ vendor/github.com/containers/storage/pkg/lockfile/lockfile_unix.go
@@ -1,5 +1,5 @@
-//go:build linux || solaris || darwin || freebsd
-// +build linux solaris darwin freebsd
+//go:build linux || solaris || darwin || freebsd || netbsd
+// +build linux solaris darwin freebsd netbsd
 
 package lockfile
 
@@ -81,7 +81,7 @@ func lockHandle(fd fileHandle, lType loc
 	}
 	lk := unix.Flock_t{
 		Type:   int16(fType),
-		Whence: int16(unix.SEEK_SET),
+		Whence: int16(0),
 		Start:  0,
 		Len:    0,
 	}
