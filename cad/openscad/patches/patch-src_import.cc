$NetBSD: patch-src_import.cc,v 1.1 2020/05/14 13:16:19 mef Exp $

boost 1.73 adaptation

--- src/import.cc.orig	2019-05-10 14:03:44.000000000 +0900
+++ src/import.cc	2020-05-14 21:43:09.208595797 +0900
@@ -50,7 +50,7 @@ namespace fs = boost::filesystem;
 #include <boost/assign/std/vector.hpp>
 using namespace boost::assign; // bring 'operator+=()' into scope
 
-#include <boost/detail/endian.hpp>
+#include <boost/endian.hpp>
 #include <cstdint>
 
 extern PolySet * import_amf(std::string, const Location &loc);
