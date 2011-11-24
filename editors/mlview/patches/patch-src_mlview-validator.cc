$NetBSD: patch-src_mlview-validator.cc,v 1.1 2011/11/24 14:13:19 joerg Exp $

--- src/mlview-validator.cc.orig	2011-11-24 02:26:56.000000000 +0000
+++ src/mlview-validator.cc
@@ -25,6 +25,7 @@
 
 #include "mlview-validator.h"
 #include "mlview-safe-ptr-utils.h"
+#include <memory>
 
 #define MESSAGE_LINE_LENGTH 55
 namespace mlview
