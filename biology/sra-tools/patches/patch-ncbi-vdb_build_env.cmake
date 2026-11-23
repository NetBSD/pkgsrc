$NetBSD: patch-ncbi-vdb_build_env.cmake,v 1.1 2026/11/23 08:07:34 wiz Exp $

Fix build with cmake 4.5.

--- ncbi-vdb/build/env.cmake.orig	2026-11-23 08:00:12.805190644 +0000
+++ ncbi-vdb/build/env.cmake
@@ -384,7 +384,7 @@ if ( SINGLE_CONFIG )
 
 if(NOT _NCBIVDB_CFG_PACKAGING)
 if ( SINGLE_CONFIG )
-    install( SCRIPT CODE
+    install( CODE
         "execute_process(COMMAND /bin/bash -c \"${CMAKE_SOURCE_DIR}/build/install-root.sh ${VERSION} ${INST_INCDIR} ${INST_LIBDIR} \" )"
     )
 endif()
