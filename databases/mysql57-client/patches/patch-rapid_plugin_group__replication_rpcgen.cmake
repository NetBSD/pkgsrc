$NetBSD: patch-rapid_plugin_group__replication_rpcgen.cmake,v 1.1 2017/01/12 09:39:47 jperkin Exp $

Don't depend on rpcgen, just use the pre-generated headers.

--- rapid/plugin/group_replication/rpcgen.cmake.orig	2016-11-28 13:32:52.000000000 +0000
+++ rapid/plugin/group_replication/rpcgen.cmake
@@ -64,7 +64,7 @@ FOREACH(X xcom_vp)
   SET (x_vanilla_h      ${XCOM_BASEDIR}/${X}.h.gen)
   SET (x_vanilla_c      ${XCOM_BASEDIR}/${X}_xdr.c.gen)
 
-  IF(WIN32)
+  IF(1)
     # on windows system's there is no rpcgen, thence copy
     # the files in the source directory
     ADD_CUSTOM_COMMAND(OUTPUT ${x_gen_h} ${x_gen_c} ${x_tmp_plat_h}
