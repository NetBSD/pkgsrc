$NetBSD: patch-src_file.c,v 1.1 2017/02/14 21:29:39 joerg Exp $

Newer zlib expects gzgetc argument to be correctly typed.

--- src/file.c.orig	2017-02-09 16:51:34.243801811 +0000
+++ src/file.c
@@ -154,7 +154,7 @@ static MEMWRAP *MakeMemWrap(void *tz, in
  {
   /* Bleck.  The gzip file format has the size of the uncompressed data,
      but I can't get to the info with the zlib interface(?). */
-  for(tmp->size=0; gzgetc(tz) != EOF; tmp->size++);
+  for(tmp->size=0; gzgetc((gzFile)tz) != EOF; tmp->size++);
   gzseek(tz,0,SEEK_SET);
   if(!(tmp->data=(uint8 *)FCEU_malloc(tmp->size)))
   {
@@ -529,7 +529,7 @@ int FCEU_read32le(uint32 *Bufo, FCEUFILE
 int FCEU_fgetc(FCEUFILE *fp)
 {
  if(fp->type==1)
-  return gzgetc(fp->fp); 
+  return gzgetc((gzFile)fp->fp); 
  else if(fp->type>=2)
  {
   MEMWRAP *wz;
@@ -549,7 +549,7 @@ uint64 FCEU_fgetsize(FCEUFILE *fp)
   int x,t;
   t=gztell(fp->fp);
   gzrewind(fp->fp);
-  for(x=0; gzgetc(fp->fp) != EOF; x++);
+  for(x=0; gzgetc((gzFile)fp->fp) != EOF; x++);
   gzseek(fp->fp,t,SEEK_SET);
   return(x);
  }
