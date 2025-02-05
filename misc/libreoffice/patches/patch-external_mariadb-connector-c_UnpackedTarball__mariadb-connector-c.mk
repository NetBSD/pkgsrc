$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.5 2025/02/05 03:50:02 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2025-01-30 14:16:33.688511582 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -28,6 +28,8 @@ $(eval $(call gb_UnpackedTarball_set_pat
 $(eval $(call gb_UnpackedTarball_add_patches,mariadb-connector-c,\
     external/mariadb-connector-c/clang-cl.patch.0 \
     external/mariadb-connector-c/c23.patch.0 \
+    external/mariadb-connector-c/netbsd.patch \
+    external/mariadb-connector-c/fix-debug-i386.patch.0 \
 ))
 
 # TODO are any "plugins" needed?
