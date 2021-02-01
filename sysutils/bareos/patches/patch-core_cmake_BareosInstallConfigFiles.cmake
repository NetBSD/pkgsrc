$NetBSD: patch-core_cmake_BareosInstallConfigFiles.cmake,v 1.2 2021/02/01 09:08:43 kardel Exp $

	the original build source is lax on the permissions.
	adjust permissions to match pkgsrc expectations.

--- core/cmake/BareosInstallConfigFiles.cmake.orig	2021-01-22 12:52:32.430510739 +0000
+++ core/cmake/BareosInstallConfigFiles.cmake
@@ -61,13 +61,15 @@ macro(BareosInstallConfigFiles CONFDIR C
         file(RENAME "${configfile}" "${configfile}.new")
 
         message(STATUS "copy ${configfile}.new to ${DESTCONFDIR}/${resname}")
-        file(COPY "${configfile}.new" DESTINATION "${DESTCONFDIR}/${resname}")
+        file(COPY "${configfile}.new" DESTINATION "${DESTCONFDIR}/${resname}"
+	     FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ)
         file(RENAME "${configfile}.new" "${configfile}")
       else()
         message(
           STATUS "${resname}/${fname} as ${resname}/${fname} (new installation)"
         )
-        file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
+        file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}"
+	     FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ)
       endif()
     endforeach()
   endforeach()
@@ -111,6 +113,7 @@ macro(BareosInstallConfigFiles CONFDIR C
         )
         file(COPY "${BackendConfigSrcDir}/${configfile}.new"
              DESTINATION "${DESTCONFDIR}/${dir}"
+	     FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
         )
         file(RENAME "${BackendConfigSrcDir}/${configfile}.new"
              "${BackendConfigSrcDir}/${configfile}"
@@ -119,6 +122,7 @@ macro(BareosInstallConfigFiles CONFDIR C
         message(STATUS "${configfile} as ${configfile}")
         file(COPY "${BackendConfigSrcDir}/${configfile}"
              DESTINATION "${DESTCONFDIR}/${dir}"
+	     FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
         )
       endif()
     endforeach()
@@ -140,6 +144,7 @@ macro(BareosInstallConfigFiles CONFDIR C
 
       file(COPY "${BackendConfigSrcDir}/${configfile}"
            DESTINATION "${DESTCONFDIR}/${dir}"
+	   FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
       )
     endforeach()
 
@@ -175,11 +180,14 @@ macro(BareosInstallConfigFiles CONFDIR C
             file(RENAME "${configfile}" "${configfile}.new")
             file(COPY "${configfile}.new"
                  DESTINATION "${DESTCONFDIR}/${resname}"
+		 FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
             )
             file(RENAME "${configfile}.new" "${configfile}")
           else()
             message(STATUS "${resname}/${fname} as ${resname}/${fname}")
-            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
+            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}"
+		 FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ
+	    )
           endif()
         else()
           message(STATUS "skipping .in file ${configfile}:${IS_INFILE}")
