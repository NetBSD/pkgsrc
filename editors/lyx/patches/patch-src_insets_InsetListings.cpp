$NetBSD: patch-src_insets_InsetListings.cpp,v 1.1 2022/08/22 08:12:47 markd Exp $

gcc 12

--- src/insets/InsetListings.cpp.orig	2020-12-29 16:50:45.000000000 +0000
+++ src/insets/InsetListings.cpp
@@ -45,6 +45,7 @@
 #include "support/regex.h"
 
 #include <sstream>
+#include <cstring>
 
 using namespace std;
 using namespace lyx::support;
