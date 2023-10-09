$NetBSD: patch-include-vigra-config__version.hxx,v 1.1 2023/10/09 09:39:29 adam Exp $

Fix version
https://github.com/ukoethe/vigra/issues/551

--- include/vigra/config_version.hxx.orig	2023-10-09 08:07:37.356399245 +0000
+++ include/vigra/config_version.hxx
@@ -39,7 +39,7 @@
 
     #define VIGRA_VERSION_MAJOR 1
     #define VIGRA_VERSION_MINOR 11
-    #define VIGRA_VERSION_PATCH 1
-    #define VIGRA_VERSION "1.11.1"
+    #define VIGRA_VERSION_PATCH 2
+    #define VIGRA_VERSION "1.11.2"
 
 #endif /* VIGRA_CONFIG_VERSION_HXX */
