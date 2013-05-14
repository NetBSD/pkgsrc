$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.1 2013/05/14 12:41:02 joerg Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2013-05-13 19:56:18.000000000 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
