$NetBSD: patch-Source_common.h,v 1.1 2020/11/11 10:45:52 mef Exp $

Adhoc fix for icu-68 fall out

GSICUString.m:71:18: error: use of undeclared identifier 'TRUE'
          return TRUE;
                 ^
GSICUString.m:80:18: error: use of undeclared identifier 'FALSE'
          return FALSE;
                 ^

--- Source/common.h.orig	2020-11-11 09:44:53.977561179 +0000
+++ Source/common.h
@@ -7,6 +7,14 @@
 #ifndef COMMON_H
 #define COMMON_H
 
+#ifndef TRUE
+#define TRUE (1)
+#endif
+
+#ifndef FALSE
+#define FALSE (0)
+#endif
+
 #include "config.h"
 
 #if	defined(HAVE_STRING_H)
