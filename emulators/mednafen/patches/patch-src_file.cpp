$NetBSD: patch-src_file.cpp,v 1.1 2017/02/17 17:02:45 joerg Exp $

--- src/file.cpp.orig	2017-02-17 15:57:45.217686812 +0000
+++ src/file.cpp
@@ -229,7 +229,7 @@ static MDFNFILE *MakeMemWrap(void *tz, i
    goto doret;
   }
 
-  while((howmany = gzread(tz, tmp->data + cur_size, cur_alloced - cur_size)) > 0)
+  while((howmany = gzread((gzFile)tz, tmp->data + cur_size, cur_alloced - cur_size)) > 0)
   {
    cur_size += howmany;
    cur_alloced <<= 1;
@@ -282,7 +282,7 @@ static MDFNFILE *MakeMemWrap(void *tz, i
  }
  else if(type == MDFN_FILETYPE_GZIP)
  {
-  gzclose(tz);
+  gzclose((gzFile)tz);
  }
  else if(type == MDFN_FILETYPE_ZIP)
  {
@@ -444,7 +444,7 @@ MDFNFILE * MDFN_fopen(const char *path, 
 
    if(!(fceufp = MakeMemWrap(t, 1)))
    {
-    gzclose(t);
+    gzclose((gzFile)t);
     return(0);
    }
 
