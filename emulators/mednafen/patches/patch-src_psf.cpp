$NetBSD: patch-src_psf.cpp,v 1.1 2016/12/17 14:24:37 joerg Exp $

--- src/psf.cpp.orig	2016-12-15 14:21:49.256613383 +0000
+++ src/psf.cpp
@@ -225,7 +225,7 @@ static PSFINFO *LoadPSF(void (*datafunc)
           {
            char linebuf[1024];
 
-           while(MDFN_fgets(linebuf,1024,fp)>0)
+           while(MDFN_fgets(linebuf,1024,fp))
            {
             int x;
 	    char *key=0,*value=0;
