$NetBSD: patch-src_api_php_sql__relay.cpp,v 1.1 2014/11/17 19:00:39 joerg Exp $

Don't mess with system headers by pretending to be C or removing defines.
Just expect php.h to work.

--- src/api/php/sql_relay.cpp.orig	2014-09-02 01:51:20.000000000 +0000
+++ src/api/php/sql_relay.cpp
@@ -3,39 +3,7 @@
 
 #include <sqlrelay/sqlrclient.h>
 
-#ifdef WIN32
-	#undef uid_t
-	#undef gid_t
-	#undef ssize_t
-	#undef socklen_t
-	#undef pid_t
-	#undef mode_t
-	#define PHP_WIN32
-	#define ZEND_WIN32
-	#define ZEND_DEBUG 0
-	#define ZTS 1
-#endif
-
-extern "C" {
-	#ifndef WIN32
-		#ifdef __cplusplus
-			#undef __cplusplus
-			#define cpluspluswasdefined
-		#endif
-		#ifndef HAVE_SOCKLEN_T
-			#define HAVE_SOCKLEN_T
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
 
