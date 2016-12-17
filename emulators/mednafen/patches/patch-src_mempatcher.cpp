$NetBSD: patch-src_mempatcher.cpp,v 1.1 2016/12/17 14:24:37 joerg Exp $

--- src/mempatcher.cpp.orig	2016-12-15 14:21:04.855680936 +0000
+++ src/mempatcher.cpp
@@ -191,7 +191,7 @@ static bool SeekToOurSection(FILE *fp) /
 {
  char buf[2048];
 
- while(fgets(buf,2048,fp) > 0)
+ while(fgets(buf,2048,fp))
  {
   if(buf[0] == '[')
   {
@@ -243,7 +243,7 @@ void MDFN_LoadGameCheats(FILE *override)
 
  if(SeekToOurSection(fp))
  {
-  while(fgets(linebuf,2048,fp) > 0)
+  while(fgets(linebuf,2048,fp))
   { 
    char namebuf[2048];
    char *tbuf=linebuf;
@@ -382,7 +382,7 @@ void MDFN_FlushGameCheats(int nosave)
   {
    FILE *tmp_fp = fopen(tmp_fn.c_str(), "wb");
 
-   while(fgets((char*)linebuf, 2048, fp) > 0)
+   while(fgets((char*)linebuf, 2048, fp))
    {
     if(linebuf[0] == '[' && !insection)
     {
