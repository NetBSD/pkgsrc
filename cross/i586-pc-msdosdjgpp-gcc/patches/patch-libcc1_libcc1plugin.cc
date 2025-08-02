$NetBSD: patch-libcc1_libcc1plugin.cc,v 1.1 2025/08/02 19:00:21 js Exp $

--- libcc1/libcc1plugin.cc.orig	2025-08-02 18:43:08.459850877 +0000
+++ libcc1/libcc1plugin.cc
@@ -32,6 +32,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
