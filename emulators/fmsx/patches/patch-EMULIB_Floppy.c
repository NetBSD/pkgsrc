$NetBSD: patch-EMULIB_Floppy.c,v 1.1 2012/07/18 23:23:21 marino Exp $

Make compatible with libz >= 1.2.6

--- EMULib/Floppy.c.orig	2007-12-30 15:59:58.000000000 +0000
+++ EMULib/Floppy.c
@@ -436,9 +436,9 @@ byte *DSKLoad(const char *Name,byte *Dsk
   }
 
 #ifdef ZLIB
-#define fopen          gzopen
-#define fclose         gzclose
-#define fread(B,L,N,F) gzread(F,B,(L)*(N))
+#define fopen(F,M)     gzopen(F,M)
+#define fclose(F)      gzclose((gzFile)F)
+#define fread(B,L,N,F) gzread((gzFile)F,B,(L)*(N))
 #endif
 
   /* Assume <Name> to be a disk image file */
@@ -504,9 +504,9 @@ const byte *DSKSave(const char *Name,con
   }
 
 #ifdef ZLIB
-#define fopen           gzopen
-#define fclose          gzclose
-#define fwrite(B,L,N,F) gzwrite(F,(byte *)B,(L)*(N))
+#define fopen(F,M)      gzopen(F,M)
+#define fclose(F)       gzclose((gzFile)F)
+#define fwrite(B,L,N,F) gzwrite((gzFile)F,(byte *)B,(L)*(N))
 #endif
 
   /* Assume <Name> to be a disk image file */
