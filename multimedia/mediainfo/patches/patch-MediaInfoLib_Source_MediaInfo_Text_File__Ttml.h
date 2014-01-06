$NetBSD: patch-MediaInfoLib_Source_MediaInfo_Text_File__Ttml.h,v 1.1 2014/01/06 22:14:29 joerg Exp $

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
