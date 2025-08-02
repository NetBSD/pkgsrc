$NetBSD: patch-libcc1_libcp1plugin.cc,v 1.1 2025/08/02 19:00:21 js Exp $

--- libcc1/libcp1plugin.cc.orig	2025-08-02 18:51:37.619890173 +0000
+++ libcc1/libcp1plugin.cc
@@ -33,6 +33,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
