$NetBSD: patch-src_futils.cpp,v 1.7 2023/11/08 21:15:37 nros Exp $

Include image_int.hpp for Internal::stringFormat().

--- src/futils.cpp.orig	2023-11-06 12:17:09.000000000 +0000
+++ src/futils.cpp
@@ -6,6 +6,7 @@
 #include "config.h"
 #include "enforce.hpp"
 #include "error.hpp"
+#include "image_int.hpp"
 #include "utils.hpp"
 
 // + standard includes
