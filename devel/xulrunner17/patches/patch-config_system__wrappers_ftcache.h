$NetBSD: patch-config_system__wrappers_ftcache.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- config/system_wrappers/ftcache.h.orig	2014-05-14 20:52:07.000000000 +0000
+++ config/system_wrappers/ftcache.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <ftcache.h>
+#pragma GCC visibility pop
