$NetBSD: patch-mednafen_mempatcher.cpp,v 1.1 2017/02/08 00:02:18 joerg Exp $

Pointers are not relative to 0.

--- mednafen/mempatcher.cpp.orig	2017-01-08 19:45:01.356354564 +0000
+++ mednafen/mempatcher.cpp
@@ -196,7 +196,7 @@ static bool SeekToOurSection(void *fp_pt
    FILE *fp = (FILE*)fp_ptr;
    char buf[2048];
 
-   while(fgets(buf,2048,fp) > 0)
+   while(fgets(buf,2048,fp))
    {
       if(buf[0] == '[')
       {
@@ -253,7 +253,7 @@ void MDFN_LoadGameCheats(void *override_
 
  if(SeekToOurSection(fp))
  {
-  while(fgets(linebuf,2048,fp) > 0)
+  while(fgets(linebuf,2048,fp))
   { 
    char namebuf[2048];
    char *tbuf=linebuf;
@@ -395,7 +395,7 @@ void MDFN_FlushGameCheats(int nosave)
   {
    FILE *tmp_fp = fopen(tmp_fn.c_str(), "wb");
 
-   while(fgets((char*)linebuf, 2048, fp) > 0)
+   while(fgets((char*)linebuf, 2048, fp))
    {
     if(linebuf[0] == '[' && !insection)
     {
