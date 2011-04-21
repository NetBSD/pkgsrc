$NetBSD: patch-src_lib_util_astring.h,v 1.6 2011/04/21 20:42:44 wiz Exp $

To avoid confusion with the ctype macros of the same name.

--- src/lib/util/astring.h.orig	2011-02-01 20:29:56.000000000 +0000
+++ src/lib/util/astring.h
@@ -43,8 +43,15 @@
 #define __ASTRING_H__
 
 #include <stdarg.h>
+#include <ctype.h>
 #include "osdcomm.h"
 
+#ifdef toupper
+#undef toupper
+#endif
+#ifdef tolower
+#undef tolower
+#endif
 
 /***************************************************************************
     TYPE DEFINITIONS
