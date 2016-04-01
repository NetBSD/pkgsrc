$NetBSD: patch-src_printtable.cpp,v 1.1 2016/04/01 19:56:02 joerg Exp $

--- src/printtable.cpp.orig	2016-04-01 19:47:54.585451048 +0000
+++ src/printtable.cpp
@@ -28,7 +28,6 @@
 #include <sstream>
 #include <vector>
 #include <algorithm>
-using namespace std;
 
 #include "wx/wxprec.h"
 
@@ -74,6 +73,8 @@ using namespace std;
 
 #include "printtable.h"
 
+using namespace std;
+
 void PrintCell::Init( const wxString& _content, wxDC* _dc, int _width, int _cellpadding, bool _bold_font )
 {
     bold_font   = _bold_font;
