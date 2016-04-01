$NetBSD: patch-src_routeprintout.cpp,v 1.1 2016/04/01 19:56:02 joerg Exp $

--- src/routeprintout.cpp.orig	2016-04-01 19:46:52.064847404 +0000
+++ src/routeprintout.cpp
@@ -24,7 +24,6 @@
  **************************************************************************/
 
 #include <iostream>
-using namespace std;
 
 #include "wx/wxprec.h"
 
@@ -72,6 +71,8 @@ using namespace std;
 #include "printtable.h"
 #include "wx28compat.h"
 
+using namespace std;
+
 #define PRINT_WP_NAME 0
 #define PRINT_WP_POSITION 1
 #define PRINT_WP_COURSE 2
