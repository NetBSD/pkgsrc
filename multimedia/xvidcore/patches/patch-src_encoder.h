$NetBSD: patch-src_encoder.h,v 1.1 2025/04/29 09:40:43 tnn Exp $

* don't redefine bool

--- src/encoder.h.orig	2025-04-29 09:39:08.818123036 +0000
+++ src/encoder.h
@@ -42,7 +42,7 @@
  * Types
  ****************************************************************************/
 
-typedef int bool;
+#include <stdbool.h>
 
 /*****************************************************************************
  * Structures
