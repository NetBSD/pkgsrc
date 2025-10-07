$NetBSD: patch-core_src_os_unix_gnatcoll-os-libc__constants____linux.ads,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

Add Linux constants definition

--- core/src/os/unix/gnatcoll-os-libc_constants__linux.ads.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/gnatcoll-os-libc_constants__linux.ads
@@ -35,4 +35,14 @@
    O_NONBLOCK : constant := 8#00004000#;
    O_CLOEXEC  : constant := 8#02000000#;
 
+   POSIX_FADV_NORMAL     : constant := 0;
+   POSIX_FADV_SEQUENTIAL : constant := 1;
+   POSIX_FADV_RANDOM     : constant := 2;
+   POSIX_FADV_NOREUSE    : constant := 3;
+   POSIX_FADV_WILLNEED   : constant := 4;
+
+   EPERM      : constant := 1;
+   EINVAL     : constant := 22;
+   ENOSYS     : constant := 38;
+
 end GNATCOLL.OS.Libc_Constants;
