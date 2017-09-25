$NetBSD: patch-src_printtable.cpp,v 1.3 2017/09/25 22:31:25 joerg Exp $

Repeat after me: I don't know what 3rd party headers are doing, so I
won't inflict my namespace decisions on them.

--- src/printtable.cpp.orig	2017-09-25 20:13:02.634455468 +0000
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
