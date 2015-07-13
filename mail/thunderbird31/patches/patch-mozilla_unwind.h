$NetBSD: patch-mozilla_unwind.h,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/unwind.h.orig	2014-07-27 06:20:09.000000000 +0000
+++ mozilla/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
