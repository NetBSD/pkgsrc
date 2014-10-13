$NetBSD: patch-MediaInfoLib_Source_MediaInfo_Text_File__Ttml.h,v 1.2 2014/10/13 09:36:29 wiz Exp $

Forward declarations may not be namespace qualified.

--- MediaInfoLib/Source/MediaInfo/Text/File_Ttml.h.orig	2014-01-06 09:53:28.000000000 +0000
+++ MediaInfoLib/Source/MediaInfo/Text/File_Ttml.h
@@ -19,8 +19,10 @@
 #include "MediaInfo/File__Analyze.h"
 //---------------------------------------------------------------------------
 
-class tinyxml2::XMLDocument;
-class tinyxml2::XMLElement;
+namespace tinyxml2 {
+class XMLDocument;
+class XMLElement;
+}
 
 namespace MediaInfoLib
 {
