$NetBSD: patch-deps_v8_src_runtime_runtime-i18n.cc,v 1.1 2017/04/29 12:35:29 ryoon Exp $

* Fix build with icu 59.1

--- deps/v8/src/runtime/runtime-i18n.cc.orig	2017-04-11 15:48:44.000000000 +0000
+++ deps/v8/src/runtime/runtime-i18n.cc
@@ -41,6 +41,7 @@
 #include "unicode/uloc.h"
 #include "unicode/unistr.h"
 #include "unicode/unum.h"
+#include "unicode/ustring.h"
 #include "unicode/uversion.h"
 
 
