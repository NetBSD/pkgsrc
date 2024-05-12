$NetBSD: patch-SP_code_splines_util__str.cpp,v 1.1 2024/05/12 17:51:55 nia Exp $

Fix building with older C++ compilers (e.g. GCC 4)

--- SP/code/splines/util_str.cpp.orig	2024-05-12 16:37:17.000000000 +0000
+++ SP/code/splines/util_str.cpp
@@ -31,7 +31,7 @@ If you have questions concerning this li
 #include "util_str.h"
 #include "q_splineshared.h"
 #include <stdlib.h>
-#include <ctype.h>
+#include <cctype>
 #include <stdio.h>
 #include <stdarg.h>
 
@@ -51,7 +51,7 @@ char *idStr::tolower
 	s = s1;
 	while ( *s )
 	{
-		*s = ::tolower( *s );
+		*s = std::tolower( *s );
 		s++;
 	}
 
@@ -67,7 +67,7 @@ char *idStr::toupper
 	s = s1;
 	while ( *s )
 	{
-		*s = ::toupper( *s );
+		*s = std::toupper( *s );
 		s++;
 	}
 
