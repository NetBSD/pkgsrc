$NetBSD: patch-src_FreeBSD_loadavg.c,v 1.1 2026/06/18 16:07:13 nia Exp $

Include config.h before any #if checks are done, so that they actually
pass.

This is necessary so that stdlib.h gets correctly included, otherwise
it implicitly declares loadavg(3) and fails to build with a modern
compiler.

--- src/FreeBSD/loadavg.c.orig	2026-06-18 16:00:24.941272671 +0000
+++ src/FreeBSD/loadavg.c
@@ -3,2 +3,3 @@
  */
+#include "config.h"
 #include "loadavg.h"
