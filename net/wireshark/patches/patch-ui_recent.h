$NetBSD: patch-ui_recent.h,v 1.1 2021/03/23 10:48:42 adam Exp $

Fix building with Glib 2.68.

--- ui/recent.h.orig	2021-03-23 09:22:16.000000000 +0000
+++ ui/recent.h
@@ -12,11 +12,12 @@
 #ifndef __RECENT_H__
 #define __RECENT_H__
 
+#include <glib.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
-#include <glib.h>
 #include <stdio.h>
 #include "epan/timestamp.h"
 #include "ui/ws_ui_util.h"
