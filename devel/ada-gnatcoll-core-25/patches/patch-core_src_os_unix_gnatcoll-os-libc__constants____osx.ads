$NetBSD: patch-core_src_os_unix_gnatcoll-os-libc__constants____osx.ads,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

Add MacOS constants definition

--- core/src/os/unix/gnatcoll-os-libc_constants__osx.ads.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/gnatcoll-os-libc_constants__osx.ads
@@ -24,14 +24,24 @@
 package GNATCOLL.OS.Libc_Constants is
 
    O_RDONLY   : constant := 16#0000#;
-   O_WRONLY   : constant := 16#0000#;
+   O_WRONLY   : constant := 16#0001#;
    O_RDWR     : constant := 16#0002#;
-   O_NONBLOCK : constant := 16#0004#;
-   O_APPEND   : constant := 16#0008#;
-   O_CREAT    : constant := 16#0200#;
-   O_TRUNC    : constant := 16#0400#;
-   O_EXCL     : constant := 16#0800#;
-   O_NOCTTY   : constant := 16#20000#;
-   O_CLOEXEC  : constant := 16#1000000#;
+   O_NONBLOCK : constant := 16#00000004#;
+   O_APPEND   : constant := 16#00000008#;
+   O_CREAT    : constant := 16#00000200#;
+   O_TRUNC    : constant := 16#00000400#;
+   O_EXCL     : constant := 16#00000800#;
+   O_NOCTTY   : constant := 16#00020000#;
+   O_CLOEXEC  : constant := 16#01000000#;
+
+   POSIX_FADV_NORMAL     : constant := 0;
+   POSIX_FADV_SEQUENTIAL : constant := 2;
+   POSIX_FADV_RANDOM     : constant := 1;
+   POSIX_FADV_NOREUSE    : constant := 5;
+   POSIX_FADV_WILLNEED   : constant := 3;
+
+   EPERM      : constant := 1;
+   EINVAL     : constant := 22;
+   ENOSYS     : constant := 78;
 
 end GNATCOLL.OS.Libc_Constants;
