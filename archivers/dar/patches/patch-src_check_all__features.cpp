$NetBSD: patch-src_check_all__features.cpp,v 1.1 2011/08/20 16:02:23 cheusov Exp $

exit(3) is declared in stdlib.h (fix for NetBSD)
--- src/check/all_features.cpp.orig	2011-03-31 19:21:02.000000000 +0000
+++ src/check/all_features.cpp
@@ -27,6 +27,8 @@
 
 #include "libdar.hpp"
 
+#include <stdlib.h>
+
 using namespace libdar;
 using namespace std;
 
