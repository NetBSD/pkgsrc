$NetBSD: patch-Modules_ManageVersion.cmake,v 1.1 2012/08/13 11:50:45 obache Exp $

* No need to remove CMakeCache.txt when doing update
http://git.fedorahosted.org/cgit/cmake-fedora.git/commit/Modules/ManageVersion.cmake?id=80f67e1bf0eb8e704d333a7999f7b4713e88a44c

--- Modules/ManageVersion.cmake.orig	2012-07-22 19:33:19.000000000 +0000
+++ Modules/ManageVersion.cmake
@@ -118,18 +118,14 @@ IF(NOT DEFINED _MANAGE_VERSION_CMAKE_)
 	SET(CMAKE_CACHE_TXT "${CMAKE_BINARY_DIR}/CMakeCache.txt")
 
 	ADD_CUSTOM_COMMAND(OUTPUT ${CHANGELOG_FILE}
-	    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_CACHE_TXT}
 	    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
 	    DEPENDS ${RELEASE_NOTES_FILE} ${CHANGELOG_PREV_FILE}
-	    COMMENT "ChangeLog is older than ${RELEASE_NOTES_FILE}. Rebuilding"
+	    COMMENT "Building ${CHANGELOG_FILE}"
 	    VERBATIM
 	    )
 
 	ADD_CUSTOM_TARGET(changelog ALL
-	    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_CACHE_TXT}
-	    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
-	    DEPENDS ${RELEASE_NOTES_FILE} ${CHANGELOG_PREV_FILE}
-	    COMMENT "Building ChangeLog"
+	    DEPENDS ${CHANGELOG_FILE}
 	    VERBATIM
 	    )
 
