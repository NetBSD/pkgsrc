$NetBSD: patch-Modules_ManageGConf.cmake,v 1.1 2013/12/28 04:59:36 obache Exp $

* Honor GCONF_SCHEMAS_INSTALLED_DIR as document

--- Modules/ManageGConf.cmake.orig	2013-12-17 09:08:18.000000000 +0000
+++ Modules/ManageGConf.cmake
@@ -60,8 +60,8 @@ IF(NOT DEFINED _MANAGE_GCONF_CMAKE_)
 	COMMENT "Installing schemas"
 	)
 
-    MANAGE_FILE_INSTALL(SYSCONF ${GCONF_SCHEMAS_FILE}
-	DEST_SUBDIR "gconf/schemas")
+    INSTALL(FILES ${GCONF_SCHEMAS_FILE}
+	DESTINATION "${GCONF_SCHEMAS_INSTALLED_DIR}")
 ENDIF(NOT DEFINED _MANAGE_GCONF_CMAKE_)
 
 
