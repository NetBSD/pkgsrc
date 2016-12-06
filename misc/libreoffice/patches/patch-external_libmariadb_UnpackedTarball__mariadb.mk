$NetBSD: patch-external_libmariadb_UnpackedTarball__mariadb.mk,v 1.1 2016/12/06 15:21:00 ryoon Exp $

--- external/libmariadb/UnpackedTarball_mariadb.mk.orig	2016-08-12 02:10:22.557004962 +0000
+++ external/libmariadb/UnpackedTarball_mariadb.mk
@@ -31,6 +31,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
     $(if $(filter MSC,$(COM)),external/libmariadb/mariadb-msvc.patch.1) \
     external/libmariadb/mariadb-inline.patch.1 \
     external/libmariadb/mariadb-CONC-104.patch.1 \
+    external/libmariadb/mariadb-netbsd.patch \
 ))
 
 # vim: set noet sw=4 ts=4:
