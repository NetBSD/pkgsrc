$NetBSD: patch-MediaInfoLib_Source_MediaInfo_Multiple_File__MpegPs.cpp,v 1.1.2.2 2021/10/16 18:09:25 tm Exp $

Fix for CVE-2020-15395
https://github.com/MediaArea/MediaInfoLib/commit/7b935cda2db88bfb63bda157bb93d69091c2c199

--- MediaInfoLib/Source/MediaInfo/Multiple/File_MpegPs.cpp.orig	2020-04-03 12:46:46.000000000 +0000
+++ MediaInfoLib/Source/MediaInfo/Multiple/File_MpegPs.cpp
@@ -405,7 +405,7 @@ void File_MpegPs::Streams_Fill_PerStream
             Fill(Stream_Audio, StreamPos_Last, Audio_MuxingMode, "SL");
     #endif //MEDIAINFO_MPEG4_YES
 
-    if (Counts[StreamKind_Last]+Count==Count_Get(StreamKind_Last)) //Old method
+    if (StreamKind_Last<Stream_Max && Counts[StreamKind_Last]+Count==Count_Get(StreamKind_Last)) //Old method
         Streams_Fill_PerStream_PerKind(StreamID, Temp, KindOfStream, Count);
     else
     {
