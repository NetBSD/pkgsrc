$NetBSD: patch-src_NetBSD_loadavg.c,v 1.1 2026/06/18 16:07:13 nia Exp $

Include config.h before any #if checks are done, so that they actually
pass.

This is necessary so that stdlib.h gets correctly included, otherwise
it implicitly declares loadavg(3) and fails to build with a modern
compiler.

--- src/NetBSD/loadavg.c.orig	2026-06-18 16:00:02.062571046 +0000
+++ src/NetBSD/loadavg.c
@@ -3,2 +3,3 @@
  */
+#include "config.h"
 #include "loadavg.h"
