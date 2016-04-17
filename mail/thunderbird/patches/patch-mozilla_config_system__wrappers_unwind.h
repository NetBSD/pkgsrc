$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.3 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2016-04-17 13:47:46.241139741 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
