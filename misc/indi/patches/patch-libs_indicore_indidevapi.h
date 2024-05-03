$NetBSD: patch-libs_indicore_indidevapi.h,v 1.1 2024/05/03 11:17:14 wiz Exp $

Always include stdarg.h for va_args.

--- libs/indicore/indidevapi.h.orig	2024-05-03 10:30:01.998627645 +0000
+++ libs/indicore/indidevapi.h
@@ -93,9 +93,7 @@
  *
  */
 
-#if defined(_WIN32) || defined(__CYGWIN__)
 #include <stdarg.h>
-#endif
 #include "indiapi.h"
 #include "lilxml.h"
 
