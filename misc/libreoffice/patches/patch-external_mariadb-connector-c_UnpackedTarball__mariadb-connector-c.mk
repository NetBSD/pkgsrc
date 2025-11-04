$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.6 2025/11/04 16:48:06 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2025-10-01 11:38:12.000000000 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -25,6 +25,8 @@ endif # $(OS),WNT
 
 $(eval $(call gb_UnpackedTarball_add_patches,mariadb-connector-c,\
     external/mariadb-connector-c/clang-cl.patch.0 \
+    external/mariadb-connector-c/netbsd.patch \
+    external/mariadb-connector-c/fix-debug-i386.patch.0 \
 ))
 
 # TODO are any "plugins" needed?
