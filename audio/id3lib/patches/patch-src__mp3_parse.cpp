$NetBSD: patch-src__mp3_parse.cpp,v 1.1 2018/10/12 13:51:59 martin Exp $

Fix a miscalculation of the VBR maximal header size,
upstream has already been notified (there is a user
review about this issue)

--- src/mp3_parse.cpp.orig	2003-03-02 01:23:00.000000000 +0100
+++ src/mp3_parse.cpp	2018-10-12 15:46:21.863323611 +0200
@@ -465,7 +465,7 @@ bool Mp3Info::Parse(ID3_Reader& reader, 
   // from http://www.xingtech.com/developer/mp3/
 
   const size_t VBR_HEADER_MIN_SIZE = 8;     // "xing" + flags are fixed
-  const size_t VBR_HEADER_MAX_SIZE = 116;   // frames, bytes, toc and scale are optional
+  const size_t VBR_HEADER_MAX_SIZE = 120;   // frames, bytes, toc and scale are optional
 
   if (mp3size >= vbr_header_offest + VBR_HEADER_MIN_SIZE) 
   {
