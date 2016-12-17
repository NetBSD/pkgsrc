$NetBSD: patch-src_nes_ines.cpp,v 1.1 2016/12/17 14:24:37 joerg Exp $

--- src/nes/ines.cpp.orig	2016-12-15 14:08:23.897104355 +0000
+++ src/nes/ines.cpp
@@ -323,7 +323,7 @@ static void SetInput(void)
 	};
  int x=0;
 
- while(moo[x].input1 > 0 || moo[x].input2 > 0 || moo[x].inputfc > 0)
+ while(moo[x].input1 || moo[x].input2 || moo[x].inputfc)
  {
   if(moo[x].crc32==iNESGameCRC32)
   {
