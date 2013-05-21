$NetBSD: patch-timing.cpp,v 1.1 2013/05/21 16:37:46 joerg Exp $

--- timing.cpp.orig	2013-05-21 14:42:27.000000000 +0000
+++ timing.cpp
@@ -16,13 +16,19 @@
 #include <ctime>
 #include <iostream>
 #include "timing.h"
-#include <tr1/unordered_map>
 #include <vector>
 #include <algorithm>
 #include <utility>
 #include <cmath>
 #include <cstring>
 
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <unordered_map>
+#else
+#include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
+
 using namespace std;
 
 //! A simple class to toggle timing information on and off
@@ -43,7 +49,7 @@ bool string_compare(const char *a, const
 
 bool FHEtimersOn=false;
 
-typedef tr1::unordered_map<const char*,FHEtimer>timerMap;
+typedef unordered_map<const char*,FHEtimer>timerMap;
 static timerMap timers;
 
 // Reset a timer for some label to zero
