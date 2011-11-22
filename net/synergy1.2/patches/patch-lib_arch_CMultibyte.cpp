$NetBSD: patch-lib_arch_CMultibyte.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/arch/CMultibyte.cpp.orig	2011-11-22 19:34:33.000000000 +0000
+++ lib/arch/CMultibyte.cpp
@@ -18,15 +18,13 @@
 #include "common.h"
 #include "CArch.h"
 #include <limits.h>
+#include <stdlib.h>
 #include <string.h>
 #if HAVE_LOCALE_H
 #	include <locale.h>
 #endif
 #if HAVE_WCHAR_H || defined(_MSC_VER)
 #	include <wchar.h>
-#elif __APPLE__
-	// wtf?  Darwin puts mbtowc() et al. in stdlib
-#	include <stdlib.h>
 #else
 	// platform apparently has no wchar_t support.  provide dummy
 	// implementations.  hopefully at least the C++ compiler has
