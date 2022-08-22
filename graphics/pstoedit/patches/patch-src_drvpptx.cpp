$NetBSD: patch-src_drvpptx.cpp,v 1.1 2022/08/22 08:23:19 markd Exp $

'std::unique_ptr' is defined in header '<memory>'

--- src/drvpptx.cpp.orig	2021-08-29 14:25:45.000000000 +0000
+++ src/drvpptx.cpp
@@ -39,6 +39,7 @@
 
 #include <errno.h>
 #include <algorithm>
+#include <memory>
 
 #ifdef _MSC_VER
 // MS VC++ Windows
