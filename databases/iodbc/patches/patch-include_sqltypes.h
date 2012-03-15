$NetBSD: patch-include_sqltypes.h,v 1.1 2012/03/15 14:50:56 abs Exp $

--- include/sqltypes.h.orig	2009-09-09 20:06:24.000000000 +0000
+++ include/sqltypes.h
@@ -400,18 +400,7 @@ typedef unsigned short SQLWCHAR;
 #else
 #  include <stdlib.h>
 
-#  if defined(__cplusplus)		|| \
-      defined(_WCHAR_T)			|| \
-      defined(_WCHAR_T_DEFINED)		|| \
-      defined(_WCHAR_T_DEFINED_)	|| \
-      defined(_WCHAR_T_DECLARED)	|| \
-      defined(_BSD_WCHAR_T_DEFINED_)	|| \
-      defined(_BSD_WCHAR_T_)		|| \
-      defined(_BSD_CT_RUNE_T_)
 typedef wchar_t SQLWCHAR;
-#  else
-#    error Please make sure your system supports the wchar_t type
-#  endif
 #endif /* WIN32 */
 
 
