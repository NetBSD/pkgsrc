$NetBSD: patch-rapid_plugin_group__replication_rpcgen.cmake,v 1.2 2018/11/13 11:24:38 markd Exp $

Don't depend on rpcgen, just use the pre-generated headers.

--- rapid/plugin/group_replication/rpcgen.cmake.orig	2018-06-08 09:56:29.000000000 +0000
+++ rapid/plugin/group_replication/rpcgen.cmake
@@ -64,7 +64,12 @@ FOREACH(X xcom_vp)
   SET (x_vanilla_h      ${XCOM_BASEDIR}/${X}.h.gen)
   SET (x_vanilla_c      ${XCOM_BASEDIR}/${X}_xdr.c.gen)
 
-  IF(WIN32)
+  IF(1)
+    IF(RPC_INCLUDE_DIR STREQUAL "/usr/include/tirpc")
+      INCLUDE_DIRECTORIES(SYSTEM /usr/include/tirpc)
+      ADD_DEFINITIONS(-DHAVE_TIRPC)
+      SET(TIRPC_LIBRARY tirpc)
+    ENDIF()
     # on windows system's there is no rpcgen, thence copy
     # the files in the source directory
     ADD_CUSTOM_COMMAND(OUTPUT ${x_gen_h} ${x_gen_c} ${x_tmp_plat_h}
