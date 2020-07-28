$NetBSD: patch-core_cmake_BareosInstallConfigFiles.cmake,v 1.1 2020/07/28 06:36:29 kardel Exp $

	The original build source is lax on the permissions.
	Adjust permission to match pkgsrc expectations.

--- core/cmake/BareosInstallConfigFiles.cmake.orig	2020-07-09 17:39:20.000000000 +0000
+++ core/cmake/BareosInstallConfigFiles.cmake
@@ -69,6 +69,7 @@ macro(
         file(
           INSTALL "${configfile}.new"
           DESTINATION "${DESTCONFDIR}/${resname}"
+	  FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
         )
         file(RENAME "${configfile}.new" "${configfile}")
       else()
@@ -76,7 +77,8 @@ macro(
           STATUS
             "${resname}/${fname} as ${resname}/${fname} (new installation)"
         )
-        file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
+        file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}" 
+	     FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ)
       endif()
     endforeach()
   endforeach()
@@ -121,6 +123,7 @@ macro(
         file(
           COPY "${BackendConfigSrcDir}/${configfile}.new"
           DESTINATION "${DESTCONFDIR}/${dir}"
+	  FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
         )
         file(RENAME "${BackendConfigSrcDir}/${configfile}.new"
              "${BackendConfigSrcDir}/${configfile}")
@@ -129,6 +132,7 @@ macro(
         file(
           COPY "${BackendConfigSrcDir}/${configfile}"
           DESTINATION "${DESTCONFDIR}/${dir}"
+	  FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
         )
       endif()
     endforeach()
@@ -151,6 +155,7 @@ macro(
       file(
         COPY "${BackendConfigSrcDir}/${configfile}"
         DESTINATION "${DESTCONFDIR}/${dir}"
+	FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
       )
     endforeach()
 
@@ -183,11 +188,14 @@ macro(
             file(
               COPY "${configfile}.new"
               DESTINATION "${DESTCONFDIR}/${resname}"
+	      FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
             )
             file(RENAME "${configfile}.new" "${configfile}")
           else()
             message(STATUS "${resname}/${fname} as ${resname}/${fname}")
-            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
+            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}"
+	         FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
+	    )
           endif()
         else()
           message(STATUS "skipping .in file ${configfile}:${IS_INFILE}")
