$NetBSD: patch-mozilla_config_system__wrappers_ftlcdfil.h,v 1.1 2014/05/27 09:58:51 joerg Exp $

--- mozilla/config/system_wrappers/ftlcdfil.h.orig	2014-05-26 20:06:38.000000000 +0000
+++ mozilla/config/system_wrappers/ftlcdfil.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <ftlcdfil.h>
+#pragma GCC visibility pop
