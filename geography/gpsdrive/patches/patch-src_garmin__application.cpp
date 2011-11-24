$NetBSD: patch-src_garmin__application.cpp,v 1.1 2011/11/24 14:06:04 joerg Exp $

--- src/garmin_application.cpp.orig	2011-11-24 01:00:09.000000000 +0000
+++ src/garmin_application.cpp
@@ -26,6 +26,7 @@
 #include <iostream>
 #endif
 
+#include <cstring>
 #include <cctype>
 #include <algorithm>
 
