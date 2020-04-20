$NetBSD: patch-es-core_src_Settings.h,v 1.1 2020/04/20 00:35:23 joerg Exp $

--- es-core/src/Settings.h.orig	2020-04-19 17:25:24.616894372 +0000
+++ es-core/src/Settings.h
@@ -3,6 +3,7 @@
 #define ES_CORE_SETTINGS_H
 
 #include <map>
+#include <string>
 
 //This is a singleton for storing settings.
 class Settings
