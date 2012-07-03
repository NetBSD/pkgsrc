$NetBSD: patch-brl.c,v 1.1 2012/07/03 17:39:53 joerg Exp $

--- brl.c.orig	1994-12-12 19:15:01.000000000 +0000
+++ brl.c
@@ -140,7 +140,7 @@
 |
 \*----------------------------------------------------------------------*/
 
-
+#include <string.h>
 #include <stdio.h>
 #include <ctype.h>
 #include "tsl.h"
@@ -289,6 +289,10 @@ char *bookabbrvstr[] = { "Gen",
 			   "BAD"
 };
 
+tsl_init(char *dfname, char *path, int memlimit);
+int tsl_printtext( int vn, int vc );
+void tsl_error(int fatal, ...);
+int tsl_gettext( int vn, int vc, char *vb, int vbsize );
 
 ref_t brl_cur_vnum;		/* Current context. */
 
@@ -1118,7 +1122,7 @@ ref_t *absversep;
 
 
 
-brl_init( dfname, dfpath, memlimit )
+brl_init( char *dfname, char *dfpath, int memlimit )
 /*----------------------------------------------------------------------
 |   NAME:
 |       brl_init
@@ -1137,8 +1141,6 @@ brl_init( dfname, dfpath, memlimit )
 |
 \*----------------------------------------------------------------------*/
 
-int memlimit;
-char *dfname, *dfpath;
 {
     if (dfname == NULL)
 	dfname = "bible.data";
