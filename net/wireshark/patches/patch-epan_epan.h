$NetBSD: patch-epan_epan.h,v 1.1 2021/03/23 10:48:42 adam Exp $

Fix building with Glib 2.68.

--- epan/epan.h.orig	2021-03-23 09:17:20.000000000 +0000
+++ epan/epan.h
@@ -10,11 +10,12 @@
 #ifndef __EPAN_H__
 #define __EPAN_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
 #include <epan/tvbuff.h>
 #include <epan/prefs.h>
 #include <epan/frame_data.h>
