$NetBSD: patch-src_support_unicode.cpp,v 1.1 2012/03/10 20:55:47 markd Exp $

Fix build with gcc 4.6

--- src/support/unicode.cpp.orig	2009-05-19 20:30:43.000000000 +0000
+++ src/support/unicode.cpp
@@ -11,6 +11,7 @@
  */
 
 #include <config.h>
+#include <cstddef>
 
 #include "support/unicode.h"
 #include "support/debug.h"
