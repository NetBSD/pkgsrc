$NetBSD: patch-EMULIB_FDIDisk.c,v 1.1 2012/07/18 23:23:21 marino Exp $

Make compatible with libz >= 1.2.6

--- EMULib/FDIDisk.c.orig	2007-12-30 15:59:36.000000000 +0000
+++ EMULib/FDIDisk.c
@@ -178,13 +178,13 @@ byte *NewFDI(FDIDisk *D,int Sides,int Tr
 }
 
 #ifdef ZLIB
-#define fopen           gzopen
-#define fclose          gzclose
-#define fread(B,L,N,F)  gzread(F,B,(L)*(N))
-#define fwrite(B,L,N,F) gzwrite(F,B,(L)*(N))
-#define fseek           gzseek
-#define rewind          gzrewind
-#define ftell           gztell
+#define fopen(F,M)      gzopen(F,M)
+#define fclose(F)       gzclose((gzFile)F)
+#define fread(B,L,N,F)  gzread((gzFile)F,B,(L)*(N))
+#define fwrite(B,L,N,F) gzwrite((gzFile)F,B,(L)*(N))
+#define fseek(F,L,W)    gzseek((gzFile)F,L,W)
+#define rewind(F)       gzrewind((gzFile)F)
+#define ftell(F)        gztell((gzFile)F)
 #endif
 
 /** LoadFDI() ************************************************/
