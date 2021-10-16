$NetBSD: patch-MediaInfoLib_Source_MediaInfo_Multiple_File__Gxf.cpp,v 1.1.2.2 2021/10/16 18:09:25 tm Exp $

Fix CVE-2020-26797
https://github.com/MediaArea/MediaInfoLib/commit/7bab1c3a043784be2c90f2e54a0e5a8d7263eead

--- MediaInfoLib/Source/MediaInfo/Multiple/File_Gxf.cpp.orig	2020-04-03 12:46:46.000000000 +0000
+++ MediaInfoLib/Source/MediaInfo/Multiple/File_Gxf.cpp
@@ -1577,7 +1577,7 @@ File__Analyze* File_Gxf::ChooseParser_Ch
     File_ChannelGrouping* Parser;
     if (Audio_Count%2)
     {
-        if (!Streams[TrackID-1].IsChannelGrouping)
+        if (!TrackID || !Streams[TrackID-1].IsChannelGrouping)
             return NULL; //Not a channel grouping
 
         Parser=new File_ChannelGrouping;
