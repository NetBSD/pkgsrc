$NetBSD: patch-src_lib_mfb_mfbio.c,v 1.1 2013/03/02 17:51:49 joerg Exp $

--- src/lib/mfb/mfbio.c.orig	2013-03-01 22:43:42.000000000 +0000
+++ src/lib/mfb/mfbio.c
@@ -21,8 +21,11 @@ Author: -C- 1982 Giles C. Billingsley
 
 #include "spice.h"
 #include "mfb.h"
+#include <string.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "suffix.h"
 
 #ifdef HAS_BSDTTY
@@ -62,9 +65,8 @@ Author: -C- 1982 Giles C. Billingsley
 #endif
 #endif
 
-/* Library routines */
-char *strcpy();
-extern void free();
+
+void MFBGenCode(char *PM);
 
 static int MFBsaveflg = 0;    /* used for kludgy ungetc                */
 static int Oldsaveflg = 0;    /* ungetc for displays without keyboards */
