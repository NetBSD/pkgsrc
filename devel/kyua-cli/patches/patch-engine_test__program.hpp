$NetBSD: patch-engine_test__program.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- engine/test_program.hpp.orig	2013-05-06 08:09:43.000000000 +0000
+++ engine/test_program.hpp
@@ -40,8 +40,14 @@
 
 #include <ostream>
 #include <string>
-#include <tr1/memory>
 #include <vector>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
+#include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "engine/test_case.hpp"
 #include "utils/fs/path.hpp"
@@ -61,7 +67,7 @@ class test_program {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     test_program(const std::string&, const utils::fs::path&,
@@ -89,7 +95,7 @@ std::ostream& operator<<(std::ostream&, 
 
 
 /// Pointer to a test program.
-typedef std::tr1::shared_ptr< test_program > test_program_ptr;
+typedef shared_ptr< test_program > test_program_ptr;
 
 
 /// Collection of test programs.
