$NetBSD: patch-src_api_php_sql__relay.cpp,v 1.4 2016/07/01 17:02:39 fhajny Exp $

--- src/api/php/sql_relay.cpp.orig	2016-03-13 19:20:25.000000000 +0000
+++ src/api/php/sql_relay.cpp
@@ -24,39 +24,15 @@
 	#define ZTS 1
 #endif
 
-extern "C" {
-	#ifndef WIN32
-
-		// On some platforms (solaris), stdio.h must be included prior
-		// to including math.h or FILE will get redefined.
-		#include <stdio.h>
-
-		// php.h ultimately includes math.h and on some platforms,
-		// __cplusplus to be defined when including it.  Manually
-		// including it prior to including php.h solves this problem.
-		#include <math.h>
-
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
+// On some platforms (solaris), stdio.h must be included prior
+// to including math.h or FILE will get redefined.
+#include <stdio.h>
+
+// php.h ultimately includes math.h and on some platforms,
+// __cplusplus to be defined when including it.  Manually
+// including it prior to including php.h solves this problem.
+#include <math.h>
+#include <php.h>
 
 #include <config.h>
 
