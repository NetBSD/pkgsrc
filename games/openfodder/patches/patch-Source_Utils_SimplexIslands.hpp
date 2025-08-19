$NetBSD: patch-Source_Utils_SimplexIslands.hpp,v 1.1 2025/08/19 11:29:40 wiz Exp $

Add missing include for size_t.

--- Source/Utils/SimplexIslands.hpp.orig	2025-08-19 11:27:16.517137426 +0000
+++ Source/Utils/SimplexIslands.hpp
@@ -15,6 +15,7 @@
  *
  */
 #include <math.h>
+#include <stddef.h>
 #include <stdint.h>
 struct Grad
 {
