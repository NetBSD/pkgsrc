$NetBSD: patch-Foundation_include_Poco_RegularExpression.h,v 1.1 2016/01/16 12:15:12 ryoon Exp $

Fix build with unbundled PCRE.
https://github.com/pocoproject/poco/commit/30cb89acd2f8aba4e40bec2335246336a5cccf7d

--- Foundation/include/Poco/RegularExpression.h.orig	2015-08-04 05:20:55.000000000 +0000
+++ Foundation/include/Poco/RegularExpression.h
@@ -26,6 +26,9 @@
 #include "Poco/Foundation.h"
 #include <vector>
 
+#if defined(POCO_UNBUNDLED)
+#include <pcre.h>
+#else
 
 //
 // Copy these definitions from pcre.h
@@ -37,7 +40,7 @@ extern "C"
 	typedef struct real_pcre8_or_16 pcre;
 	struct pcre_extra;
 }
-
+#endif
 
 namespace Poco {
 
