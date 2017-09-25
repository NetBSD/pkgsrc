$NetBSD: patch-src_routeprintout.cpp,v 1.3 2017/09/25 22:31:25 joerg Exp $

Repeat after me: I don't know what 3rd party headers are doing, so I
won't inflict my namespace decisions on them.

--- src/routeprintout.cpp.orig	2017-09-25 20:10:38.997900156 +0000
+++ src/routeprintout.cpp
@@ -24,7 +24,6 @@
  **************************************************************************/
 
 #include <iostream>
-using namespace std;
 
 #include "wx/wxprec.h"
 
@@ -79,6 +78,8 @@ using namespace std;
 #define PRINT_WP_DISTANCE 3
 #define PRINT_WP_DESCRIPTION 4
 
+using namespace std;
+
 // Global print data, to remember settings during the session
 extern wxPrintData*     g_printData;
 // Global page setup data
