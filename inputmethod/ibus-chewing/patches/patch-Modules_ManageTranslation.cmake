$NetBSD: patch-Modules_ManageTranslation.cmake,v 1.3 2013/12/28 04:59:36 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageTranslation.cmake.orig	2013-12-17 15:57:40.000000000 +0000
+++ Modules/ManageTranslation.cmake
@@ -199,7 +199,7 @@ IF(NOT DEFINED _MANAGE_TRANSLATION_CMAKE
 		## No need to use MANAGE_FILE_INSTALL
 		## As this will handle by rpmbuild
 		INSTALL(FILES ${_gmoFile} DESTINATION 
-		    ${DATA_DIR}/locale/${_locale}/LC_MESSAGES 
+		    ${CMAKE_INSTALL_LOCALEDIR}/${_locale}/LC_MESSAGES 
 		    RENAME ${_opt_POTFILE_NAME}.mo
 		    )
 	    ENDFOREACH(_locale ${_opt_LOCALES})
