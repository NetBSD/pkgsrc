$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.2 2019/02/19 16:28:03 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2019-01-23 19:35:25.000000000 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -32,6 +32,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
     external/mariadb-connector-c/mariadb-inline.patch.1 \
     external/mariadb-connector-c/mariadb-CONC-104.patch.1 \
     external/mariadb-connector-c/clang-cl.patch.0 \
+    external/mariadb-connector-c/netbsd.patch \
 ))
 
 # vim: set noet sw=4 ts=4:
