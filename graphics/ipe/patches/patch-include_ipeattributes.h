$NetBSD: patch-include_ipeattributes.h,v 1.1 2025/04/07 10:18:51 wiz Exp $

For uint32_t.

--- include/ipeattributes.h.orig	2025-04-07 10:17:10.224603526 +0000
+++ include/ipeattributes.h
@@ -35,6 +35,8 @@
 #include "ipebase.h"
 #include "ipegeo.h"
 
+#include <cstdint>
+
 // --------------------------------------------------------------------
 
 namespace ipe {
