$NetBSD: patch-src_config_auto-aux_sizes.c,v 1.1 2026/07/21 14:07:29 ryoon Exp $

* Fix build with GCC 14.

--- src/config/auto-aux/sizes.c.orig	2026-06-03 12:38:56.970894058 +0000
+++ src/config/auto-aux/sizes.c
@@ -1,3 +1,5 @@
+#include <stdio.h>
+
 int main(argc, argv)
      int argc;
      char ** argv;
