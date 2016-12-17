$NetBSD: patch-src_cdrom_cdromfile.cpp,v 1.1 2016/12/17 14:24:37 joerg Exp $

--- src/cdrom/cdromfile.cpp.orig	2016-12-15 14:22:07.554338091 +0000
+++ src/cdrom/cdromfile.cpp
@@ -410,7 +410,7 @@ CDRFile *cdrfile_open(const char *path)
   CDRFILE_TRACK_INFO TmpTrack;
   memset(&TmpTrack, 0, sizeof(TmpTrack));
 
-  while(fgets(linebuf, 512, fp) > 0)
+  while(fgets(linebuf, 512, fp))
   {
    char cmdbuf[512], raw_args[512], args[4][512];
    int argcount = 0;
