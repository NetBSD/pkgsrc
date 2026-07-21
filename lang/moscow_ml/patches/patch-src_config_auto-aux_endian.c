$NetBSD: patch-src_config_auto-aux_endian.c,v 1.1 2026/07/21 14:07:29 ryoon Exp $

* Fix build with GCC 14.

--- src/config/auto-aux/endian.c.orig	2026-06-03 12:39:39.545453221 +0000
+++ src/config/auto-aux/endian.c
@@ -1,3 +1,5 @@
+#include <string.h>
+
 main()
 {
   long n[2];
