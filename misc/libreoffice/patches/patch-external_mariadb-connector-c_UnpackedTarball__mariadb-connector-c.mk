$NetBSD: patch-external_mariadb-connector-c_UnpackedTarball__mariadb-connector-c.mk,v 1.3 2020/08/11 16:07:39 ryoon Exp $

--- external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk.orig	2020-07-29 19:29:17.000000000 +0000
+++ external/mariadb-connector-c/UnpackedTarball_mariadb-connector-c.mk
@@ -27,6 +27,7 @@ $(eval $(call gb_UnpackedTarball_set_pat
 
 $(eval $(call gb_UnpackedTarball_add_patches,mariadb-connector-c,\
     external/mariadb-connector-c/clang-cl.patch.0 \
+    external/mariadb-connector-c/netbsd.patch \
 ))
 
 # TODO are any "plugins" needed?
