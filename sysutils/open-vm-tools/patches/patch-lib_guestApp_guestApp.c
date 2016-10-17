$NetBSD: patch-lib_guestApp_guestApp.c,v 1.1 2016/10/17 20:55:49 ryoon Exp $

* Fix pkgsrc powerops scripts location

--- lib/guestApp/guestApp.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/guestApp/guestApp.c
@@ -63,7 +63,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "@PREFIX@/etc/vmware-tools"
 #endif
 
 #if defined _WIN32
