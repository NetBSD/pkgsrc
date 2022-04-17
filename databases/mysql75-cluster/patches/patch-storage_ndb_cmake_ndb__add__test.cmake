$NetBSD: patch-storage_ndb_cmake_ndb__add__test.cmake,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- storage/ndb/cmake/ndb_add_test.cmake.orig	2021-09-14 09:08:08.000000000 +0000
+++ storage/ndb/cmake/ndb_add_test.cmake
@@ -32,10 +32,11 @@ FUNCTION(NDB_ADD_TEST)
     ${ARGN}
   )
 
-  # Check switch WITH_UNIT_TESTS and build only when requested
-  IF(NOT WITH_UNIT_TESTS)
+# pkgsrc
+#   # Check switch WITH_UNIT_TESTS and build only when requested
+#   IF(NOT WITH_UNIT_TESTS)
     RETURN()
-  ENDIF()
+#   ENDIF()
 
   # Extracting the executable from DEFAULT_ARGS
   LIST(GET ARG_DEFAULT_ARGS 0 EXEC)
