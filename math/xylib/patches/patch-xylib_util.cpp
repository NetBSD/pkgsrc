$NetBSD: patch-xylib_util.cpp,v 1.1 2020/01/07 13:03:50 nros Exp $

* cstdlib needed for strol

--- xylib/util.cpp.orig	2016-12-17 12:45:55.000000000 +0000
+++ xylib/util.cpp
@@ -10,6 +10,7 @@
 #include <limits>
 #include <cassert>
 #include <cerrno>
+#include <cstdlib>
 #include <boost/detail/endian.hpp>
 #include <boost/cstdint.hpp>
 
