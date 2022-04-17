$NetBSD: patch-rapid_plugin_group__replication_rpcgen.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- rapid/plugin/group_replication/rpcgen.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ rapid/plugin/group_replication/rpcgen.cmake
@@ -71,7 +71,12 @@ FOREACH(X xcom_vp)
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
