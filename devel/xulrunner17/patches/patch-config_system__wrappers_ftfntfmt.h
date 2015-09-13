$NetBSD: patch-config_system__wrappers_ftfntfmt.h,v 1.1 2015/09/13 15:09:03 joerg Exp $

--- config/system_wrappers/ftfntfmt.h.orig	2014-05-14 20:52:07.000000000 +0000
+++ config/system_wrappers/ftfntfmt.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <ftfntfmt.h>
+#pragma GCC visibility pop
