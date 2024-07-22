$NetBSD: patch-gcc_system.h,v 1.1 2024/07/22 20:01:50 tnn Exp $

XXX paper over problem on macOS

--- gcc/system.h.orig	2024-07-20 15:49:56.110873778 +0000
+++ gcc/system.h
@@ -1,3 +1,6 @@
+#if defined(__clang__) && defined(__cplusplus)
+#include <map>
+#endif
 /* Get common system includes and various definitions and declarations based
    on autoconf macros.
    Copyright (C) 1998-2023 Free Software Foundation, Inc.
