$NetBSD: patch-test_testsymboldatabase.cpp,v 1.1 2021/07/09 10:50:37 markd Exp $

gcc11 build fix

--- test/testsymboldatabase.cpp.orig	2020-06-13 16:08:37.000000000 +0000
+++ test/testsymboldatabase.cpp
@@ -31,6 +31,7 @@
 #include <cstddef>
 #include <cstdint>
 #include <cstring>
+#include <limits>
 #include <list>
 #include <map>
 #include <set>
