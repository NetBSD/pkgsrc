$NetBSD: patch-engine_test__case.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- engine/test_case.hpp.orig	2013-05-06 08:06:18.000000000 +0000
+++ engine/test_case.hpp
@@ -34,7 +34,13 @@
 
 #include <ostream>
 #include <string>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "engine/metadata.hpp"
 #include "utils/config/tree.hpp"
@@ -71,7 +77,7 @@ class test_case {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
 public:
     test_case(const std::string&, const test_program&,
@@ -96,7 +102,7 @@ std::ostream& operator<<(std::ostream&, 
 
 
 /// Pointer to a test case.
-typedef std::tr1::shared_ptr< test_case > test_case_ptr;
+typedef shared_ptr< test_case > test_case_ptr;
 
 
 test_result debug_test_case(const test_case*, const utils::config::tree&,
