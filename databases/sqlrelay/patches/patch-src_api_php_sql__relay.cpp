$NetBSD: patch-src_api_php_sql__relay.cpp,v 1.3 2015/07/05 12:52:39 joerg Exp $

--- src/api/php/sql_relay.cpp.orig	2015-07-05 10:40:12.000000000 +0000
+++ src/api/php/sql_relay.cpp
@@ -16,29 +16,7 @@
 	#define ZTS 1
 #endif
 
-extern "C" {
-	#ifndef WIN32
-		#ifdef __cplusplus
-			#undef __cplusplus
-			#define cpluspluswasdefined
-		#endif
-		#ifndef HAVE_SOCKLEN_T
-			#define HAVE_SOCKLEN_T
-		#endif
-		#ifndef _WCHAR_T_DECLARED
-			#define _WCHAR_T_DECLARED
-		#endif
-		#ifndef _WCHAR_T_DEFINED_
-			#define _WCHAR_T_DEFINED_
-		#endif
-	#endif
-	#include <php.h>
-	#ifndef WIN32
-		#ifdef cpluspluswasdefined
-			#define __cplusplus
-		#endif
-	#endif
-}
+#include <php.h>
 
 #include <config.h>
 
