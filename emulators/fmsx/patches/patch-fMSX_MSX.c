$NetBSD: patch-fMSX_MSX.c,v 1.1 2012/07/18 23:23:21 marino Exp $

Make compatible with libz >= 1.2.6

--- fMSX/MSX.c.orig	2008-01-29 22:32:53.000000000 +0000
+++ fMSX/MSX.c
@@ -2440,14 +2440,14 @@ int LoadFile(const char *FileName)
 }
 
 #ifdef ZLIB
-#define fopen           gzopen
-#define fclose          gzclose
-#define fread(B,L,N,F)  gzread(F,B,(L)*(N))
-#define fwrite(B,L,N,F) gzwrite(F,B,(L)*(N))
-#define fseek           gzseek
-#define rewind          gzrewind
-#define fgetc           gzgetc
-#define ftell           gztell
+#define fopen(F,M)      gzopen(F,M)
+#define fclose(F)       gzclose((gzFile)F)
+#define fread(B,L,N,F)  gzread((gzFile)F,B,(L)*(N))
+#define fwrite(B,L,N,F) gzwrite((gzFile)F,B,(L)*(N))
+#define fseek(F,L,W)    gzseek((gzFile)F,L,W)
+#define rewind(F)       gzrewind((gzFile)F)
+#define fgetc(F)        gzgetc((gzFile)F)
+#define ftell(F)        gztell((gzFile)F)
 #endif
 
 /** LoadFNT() ************************************************/
