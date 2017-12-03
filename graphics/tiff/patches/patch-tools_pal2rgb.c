$NetBSD: patch-tools_pal2rgb.c,v 1.1 2017/12/03 09:07:06 maya Exp $

CVE-2017-17095 Heap-based buffer overflow bug in pal2rgb

--- tools/pal2rgb.c.orig	2015-08-28 22:17:08.172200823 +0000
+++ tools/pal2rgb.c
@@ -39,6 +39,7 @@
 # include "libport.h"
 #endif
 
+#include "tiffiop.h"
 #include "tiffio.h"
 
 #define	streq(a,b)	(strcmp(a,b) == 0)
@@ -185,7 +186,7 @@
 	  register unsigned char* pp;
 	  register uint32 x;
 	  ibuf = (unsigned char*)_TIFFmalloc(TIFFScanlineSize(in));
-	  obuf = (unsigned char*)_TIFFmalloc(TIFFScanlineSize(out));
+	  obuf = (unsigned char*)_TIFFmalloc(TIFFSafeMultiply(tmsize_t, imagewidth, 3*sizeof(short)));
 	  switch (config) {
 	  case PLANARCONFIG_CONTIG:
 		for (row = 0; row < imagelength; row++) {
