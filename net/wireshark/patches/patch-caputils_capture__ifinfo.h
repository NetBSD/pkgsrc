$NetBSD: patch-caputils_capture__ifinfo.h,v 1.1 2021/03/23 10:48:42 adam Exp $

Fix building with Glib 2.68.

--- caputils/capture_ifinfo.h.orig	2021-03-23 09:25:20.000000000 +0000
+++ caputils/capture_ifinfo.h
@@ -11,12 +11,12 @@
 #ifndef __CAPTURE_IFINFO_H__
 #define __CAPTURE_IFINFO_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
-
 /*
  * Explicitly set the interface_type enum values as these values are exposed
  * in the preferences gui.interfaces_hidden_types string.
