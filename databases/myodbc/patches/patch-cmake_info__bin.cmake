$NetBSD: patch-cmake_info__bin.cmake,v 1.1 2022/12/25 08:22:26 wiz Exp $

Install into more appropriate location for pkgsrc.

--- cmake/info_bin.cmake.orig	2022-09-01 11:59:03.000000000 +0000
+++ cmake/info_bin.cmake
@@ -100,7 +100,7 @@ FUNCTION(GENERATE_INFO_BIN)
   ENDIF()
 
   CONFIGURE_FILE(INFO_BIN.in "${CMAKE_SOURCE_DIR}/INFO_BIN")
-  install(FILES "${CMAKE_SOURCE_DIR}/INFO_BIN" DESTINATION . COMPONENT Readme)
+  install(FILES "${CMAKE_SOURCE_DIR}/INFO_BIN" DESTINATION share/doc/mysql-connector-odbc COMPONENT Readme)
 ENDFUNCTION()
 
 
@@ -179,8 +179,8 @@ FUNCTION(GENERATE_INFO_SRC)
 
     CONFIGURE_FILE(INFO_SRC.in "${CMAKE_SOURCE_DIR}/INFO_SRC")
   ENDIF()
-  install(FILES "${CMAKE_SOURCE_DIR}/INFO_SRC" DESTINATION . COMPONENT Readme)
+  install(FILES "${CMAKE_SOURCE_DIR}/INFO_SRC" DESTINATION share/doc/mysql-connector-odbc COMPONENT Readme)
 ENDFUNCTION()
 
 GENERATE_INFO_SRC()
-GENERATE_INFO_BIN()
\ No newline at end of file
+GENERATE_INFO_BIN()
