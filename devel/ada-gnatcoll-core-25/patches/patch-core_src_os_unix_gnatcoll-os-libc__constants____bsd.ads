$NetBSD: patch-core_src_os_unix_gnatcoll-os-libc__constants____bsd.ads,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

Add NetBSD support

--- /dev/null
+++ core/src/os/unix/gnatcoll-os-libc_constants__bsd.ads
@@ -0,0 +1,29 @@
+--  SPDX-License-Identifier: BSD-2-Clause
+--                         : OR GPL-3.0-or-later WITH GCC-exception-3.1
+--  Copyright (C) 2025, dkazankov@NetBSD.org
+
+package GNATCOLL.OS.Libc_Constants is
+
+   --  sys/fcntl.h
+   O_RDONLY   : constant := 16#00000000#;
+   O_WRONLY   : constant := 16#00000001#;
+   O_RDWR     : constant := 16#00000002#;
+   O_NONBLOCK : constant := 16#00000004#;
+   O_APPEND   : constant := 16#00000008#;
+   O_CREAT    : constant := 16#00000200#;
+   O_TRUNC    : constant := 16#00000400#;
+   O_EXCL     : constant := 16#00000800#;
+   O_NOCTTY   : constant := 16#00008000#;
+   O_CLOEXEC  : constant := 16#00400000#;
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
+
+end GNATCOLL.OS.Libc_Constants;
