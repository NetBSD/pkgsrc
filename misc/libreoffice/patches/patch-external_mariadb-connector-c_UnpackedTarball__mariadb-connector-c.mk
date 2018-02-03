$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.1 2018/02/03 00:39:50 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2018-01-24 20:31:03.000000000 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -31,6 +31,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
     $(if $(filter MSC,$(COM)),external/mariadb-connector-c/mariadb-msvc.patch.1) \
     external/mariadb-connector-c/mariadb-inline.patch.1 \
     external/mariadb-connector-c/mariadb-CONC-104.patch.1 \
+    external/mariadb-connector-c/netbsd.patch \
 ))
 
 # vim: set noet sw=4 ts=4:
