$NetBSD: patch-lib_guestApp_guestApp.c,v 1.3 2023/02/10 01:22:08 khorben Exp $

* Fix pkgsrc powerops scripts location

--- lib/guestApp/guestApp.c.orig	2022-02-11 15:32:56.000000000 +0000
+++ lib/guestApp/guestApp.c
@@ -63,7 +63,7 @@
 #elif defined __APPLE__
 #   define GUESTAPP_TOOLS_INSTALL_PATH "/Library/Application Support/VMware Tools"
 #else
-#   define GUESTAPP_TOOLS_INSTALL_PATH "/etc/vmware-tools"
+#   define GUESTAPP_TOOLS_INSTALL_PATH "@PREFIX@/etc/vmware-tools"
 #endif
 
 #if defined _WIN32
