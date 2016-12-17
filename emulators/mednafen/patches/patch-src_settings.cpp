$NetBSD: patch-src_settings.cpp,v 1.1 2016/12/17 14:24:37 joerg Exp $

--- src/settings.cpp.orig	2016-12-15 14:21:35.471903115 +0000
+++ src/settings.cpp
@@ -166,7 +166,7 @@ bool MFDN_LoadSettings(const char *based
 
  char linebuf[1024];
 
- while(fgets(linebuf, 1024, fp) > 0)
+ while(fgets(linebuf, 1024, fp))
  {
   char *spacepos = strchr(linebuf, ' ');
   md5_context md5;
