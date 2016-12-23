$NetBSD: patch-lib_guestApp_guestApp.c,v 1.2 2016/12/23 04:11:03 ryoon Exp $

* Fix pkgsrc powerops scripts location

--- lib/guestApp/guestApp.c.orig	2016-09-29 10:07:22.000000000 +0000
+++ lib/guestApp/guestApp.c
@@ -63,7 +63,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "@PREFIX@/etc/vmware-tools"
 #endif
 
 #if defined _WIN32
