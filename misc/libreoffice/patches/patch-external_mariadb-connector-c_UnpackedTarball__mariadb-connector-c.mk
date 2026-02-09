$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.7 2026/02/09 16:59:59 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2026-01-27 21:11:38.000000000 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -32,6 +32,8 @@ $(eval $(call gb_UnpackedTarball_add_patches,mariadb-c
     external/mariadb-connector-c/clang-cl.patch.0 \
     external/mariadb-connector-c/0001-const-up-my_uca1400_collation_definitions.patch \
     external/mariadb-connector-c/0001-const-up-mariadb_defaults-and-MADB_OS_CHARSET.patch \
+    external/mariadb-connector-c/netbsd.patch \
+    external/mariadb-connector-c/fix-debug-i386.patch.0 \
 ))
 
 # TODO are any "plugins" needed?
