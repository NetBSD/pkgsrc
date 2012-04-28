$NetBSD: patch-src_string.cpp,v 1.1 2012/04/28 06:56:43 adam Exp $

Define Collator when building strgen.

--- src/string.cpp.orig	2012-04-27 16:01:34.000000000 +0000
+++ src/string.cpp
@@ -29,6 +29,9 @@
 #include <unicode/ustring.h>
 #include "language.h"
 #include "gfx_func.h"
+#if defined(STRGEN) || defined(SETTINGSGEN)
+Collator *_current_collator = NULL;
+#endif
 #endif /* WITH_ICU */
 
 /**
