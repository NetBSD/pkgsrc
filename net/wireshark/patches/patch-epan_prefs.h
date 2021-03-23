$NetBSD: patch-epan_prefs.h,v 1.1 2021/03/23 10:48:42 adam Exp $

Fix building with Glib 2.68.

--- epan/prefs.h.orig	2021-03-23 08:55:05.000000000 +0000
+++ epan/prefs.h
@@ -11,12 +11,12 @@
 #ifndef __PREFS_H__
 #define __PREFS_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 #include <epan/params.h>
 #include <epan/range.h>
 
