$NetBSD: patch-src_3rdparty_autotrace_autotrace.h,v 1.1 2021/03/23 09:57:35 ryoon Exp $

--- src/3rdparty/autotrace/autotrace.h.orig	2020-09-07 08:57:40.000000000 +0000
+++ src/3rdparty/autotrace/autotrace.h
@@ -23,6 +23,8 @@
 
 #include <stdio.h>
 
+#include "types.h"
+
 #ifdef __cplusplus
 extern "C" {
 #endif                          /* __cplusplus */
@@ -35,7 +37,6 @@ extern "C" {
  * Typedefs
  * ===================================================================== */
 
-#include "types.h"
 #include "color.h"
 
 /* Third degree is the highest we deal with.  */
