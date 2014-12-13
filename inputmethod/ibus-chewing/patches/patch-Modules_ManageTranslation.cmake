$NetBSD: patch-Modules_ManageTranslation.cmake,v 1.4 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support
* `-printf' option of find(1) is not portable.

--- Modules/ManageTranslation.cmake.orig	2014-10-28 05:05:31.000000000 +0000
+++ Modules/ManageTranslation.cmake
@@ -353,7 +353,7 @@ FUNCTION(MANAGE_POT_FILE potFile)
 
 	IF(NOT "${moDir}" STREQUAL "")
 	    ## MO file
-	    SET(_moDir  "${DATA_DIR}/locale/${_l}/LC_MESSAGES")
+	    SET(_moDir  "${LOCALE_DIR}/${_l}/LC_MESSAGES")
 	    SET(_gmoFile "${moDir}/${_l}.gmo")
 	    ADD_CUSTOM_COMMAND(OUTPUT ${_gmoFile}
 		COMMAND ${MSGFMT_EXECUTABLE} 
@@ -393,8 +393,7 @@ FUNCTION(MANAGE_GETTEXT_LOCALES localeLi
     ELSE()
 	## LOCALES is not specified, detect now
 	EXECUTE_PROCESS(
-	    COMMAND find ${poDir} -name "*.po" -printf "%f\n"
-	    COMMAND sed -e "s/.po//g"
+	    COMMAND find ${poDir} -name "*.po" -exec basename {} .po \;
 	    COMMAND sort -u
 	    COMMAND xargs
 	    COMMAND sed -e "s/ /;/g"
