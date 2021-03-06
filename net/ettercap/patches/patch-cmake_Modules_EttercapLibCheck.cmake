$NetBSD: patch-cmake_Modules_EttercapLibCheck.cmake,v 1.1 2021/03/06 11:20:56 nia Exp $

Just use pkg-config to find GTK3 rather than a custom hellfire that checks
30 system directories but nothing used by pkgsrc.

--- cmake/Modules/EttercapLibCheck.cmake.orig	2020-08-01 14:32:06.000000000 +0000
+++ cmake/Modules/EttercapLibCheck.cmake
@@ -45,24 +45,9 @@ if(ENABLE_GTK)
     unset(contains_valid)
     if(GTK_BUILD_TYPE STREQUAL GTK3)
         set(GTK3_FIND_VERSION 1)
-        find_package(GTK3 3.12.0)
+	pkg_check_modules (GTK3 gtk+-3.0)
         if(GTK3_FOUND)
           set(HAVE_GTK3 1)
-        else()
-            # give it another try but only in GTK3 compatibility mode
-            find_package(GTK3 REQUIRED)
-            if(GTK3_FOUND)
-              message("\n\
-Your version of GTK3 (${GTK3_VERSION}) is not \
-sufficient for full GTK3 support.\n\
-Full support requires >= 3.12.\n\
-Building in GTK3 compatibility mode.\n")
-              set(HAVE_GTK3COMPAT 1)
-            else()
-              message(FATAL_ERROR
-"You choose to build against GTK3.\
-Please install it, or build against GTK1")
-            endif()
         endif()
         set(EC_INTERFACES_LIBS ${EC_INTERFACES_LIBS} ${GTK3_LIBRARIES})
         set(EC_INCLUDE ${EC_INCLUDE} ${GTK3_INCLUDE_DIRS})
