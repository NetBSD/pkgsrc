$NetBSD: patch-libxorp_xorp.h,v 1.3 2013/06/13 21:48:09 joerg Exp $

--- libxorp/xorp.h.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/xorp.h
@@ -39,6 +39,7 @@
 #endif
 
 #if defined (__cplusplus) && !defined(__STL_NO_NAMESPACES)
+namespace std {};
 using namespace std;
 #endif
 
@@ -130,10 +131,6 @@ using namespace std;
 
 #include "xorp_osdep_mid.h"
 
-#if defined (__cplusplus) && !defined(__STL_NO_NAMESPACES)
-using namespace std::rel_ops;
-#endif
-
 /*
  * Misc. definitions that may be missing from the system header files.
  * TODO: this should go to a different header file.
@@ -173,9 +170,7 @@ using namespace std::rel_ops;
 #define FALSE (0)
 #define TRUE (!FALSE)
 #endif /* TRUE, FALSE */
-#ifndef __cplusplus
-typedef enum { true = TRUE, false = FALSE } bool;
-#endif
+#include <stdbool.h>
 typedef bool bool_t;
 
 /*
