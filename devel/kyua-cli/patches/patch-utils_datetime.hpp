$NetBSD: patch-utils_datetime.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/datetime.hpp.orig	2013-05-06 07:34:28.000000000 +0000
+++ utils/datetime.hpp
@@ -40,7 +40,13 @@ extern "C" {
 #include <ostream>
 #include <string>
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace utils {
 namespace datetime {
@@ -81,9 +87,9 @@ class timestamp {
     struct impl;
 
     /// Pointer to the shared internal implementation.
-    std::tr1::shared_ptr< impl > _pimpl;
+    shared_ptr< impl > _pimpl;
 
-    timestamp(std::tr1::shared_ptr< impl >);
+    timestamp(shared_ptr< impl >);
 
 public:
     static timestamp from_microseconds(const int64_t);
