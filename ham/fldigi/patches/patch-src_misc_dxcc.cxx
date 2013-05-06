$NetBSD: patch-src_misc_dxcc.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/misc/dxcc.cxx.orig	2013-05-03 14:21:04.000000000 +0000
+++ src/misc/dxcc.cxx
@@ -30,7 +30,6 @@
 #include <string>
 #include <list>
 #include <map>
-#include <tr1/unordered_map>
 #include <algorithm>
 
 #include <FL/filename.H>
@@ -43,8 +42,16 @@
 #include "confdialog.h"
 #include "main.h"
 
+#if __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
+#include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
+
 using namespace std;
-using tr1::unordered_map;
+
 
 
 dxcc::dxcc(const char* cn, int cq, int itu, const char* ct, float lat, float lon, float tz)
