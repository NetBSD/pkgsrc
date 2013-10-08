$NetBSD: patch-Modules_ManageTranslation.cmake,v 1.2 2013/10/08 12:06:23 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageTranslation.cmake.orig	2012-11-26 07:37:40.000000000 +0000
+++ Modules/ManageTranslation.cmake
@@ -198,7 +198,7 @@ IF(NOT DEFINED _MANAGE_TRANSLATION_CMAKE
 		    )
 
 		#MESSAGE("_absPoFile=${_absPoFile} _absPotDir=${_absPotDir} _lang=${_lang} curr_bin=${CMAKE_CURRENT_BINARY_DIR}")
-		INSTALL(FILES ${_absGmoFile} DESTINATION share/locale/${_locale}/LC_MESSAGES RENAME ${_potBasename}.mo)
+		INSTALL(FILES ${_absGmoFile} DESTINATION ${CMAKE_INSTALL_LOCALEDIR}/${_locale}/LC_MESSAGES RENAME ${_potBasename}.mo)
 		LIST(APPEND _absGmoFileList ${_absGmoFile})
 		LIST(APPEND _absPoFileList ${_absPoFile})
 	    ENDFOREACH(_locale ${_localeList})
