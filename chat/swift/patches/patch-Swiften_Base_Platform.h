$NetBSD: patch-Swiften_Base_Platform.h,v 1.1 2022/05/03 20:03:31 nia Exp $

Support newer Boost versions. via Arch Linux.

--- Swiften/Base/Platform.h.orig	2018-04-06 10:06:46.000000000 +0000
+++ Swiften/Base/Platform.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2010 Isode Limited.
+ * Copyright (c) 2010-2019 Isode Limited.
  * All rights reserved.
  * See the COPYING file for more information.
  */
@@ -43,9 +43,9 @@
 #endif
 
 // Endianness
-#include <boost/detail/endian.hpp>
-#if defined(BOOST_LITTLE_ENDIAN)
+#include <boost/predef/other/endian.h>
+#if defined(BOOST_ENDIAN_LITTLE_BYTE)
 #define SWIFTEN_LITTLE_ENDIAN
-#elif defined(BOOST_BIG_ENDIAN)
+#elif defined(BOOST_ENDIAN_BIG_BYTE)
 #define SWIFTEN_BIG_ENDIAN
 #endif
