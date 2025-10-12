$NetBSD: patch-metamail_codes.c,v 1.2 2025/10/12 00:57:39 mrg Exp $

- Add types for GCC 14.

--- metamail/codes.c.orig	1993-09-20 06:13:22.000000000 -0700
+++ metamail/codes.c	2025-10-11 16:49:48.546329391 -0700
@@ -14,9 +14,13 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 */
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include <config.h>
 
+#include "metamail.h"
+
 extern char *index();
+void output64chunk();
 static char basis_64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
@@ -69,6 +73,7 @@ int PortableNewlines;
 #endif
 }
 
+void
 to64(infile, outfile, PortableNewlines) 
 FILE *infile, *outfile;
 int PortableNewlines;
@@ -97,7 +102,9 @@ int PortableNewlines;
     fflush(outfile);
 }
 
+void
 output64chunk(c1, c2, c3, pads, outfile)
+int c1, c2, c3, pads;
 FILE *outfile;
 {
     putc(basis_64[c1>>2], outfile);
@@ -114,6 +121,7 @@ FILE *outfile;
     }
 }
 
+int
 PendingBoundary(s, Boundaries, BoundaryCt)
 char *s;
 char **Boundaries;
@@ -140,6 +148,7 @@ int *BoundaryCt;
 static int CRpending = 0;
 
 #ifdef NEWLINE_CHAR
+void
 almostputc(c, outfile, PortableNewlines)
 int c;
 FILE *outfile;
@@ -174,7 +183,7 @@ int PortableNewlines;
 }
 #endif
 
-from64(infile, outfile, boundaries, boundaryct, PortableNewlines) 
+void from64(infile, outfile, boundaries, boundaryct, PortableNewlines) 
 FILE *infile, *outfile;
 char **boundaries;
 int *boundaryct;
@@ -275,6 +284,7 @@ char c;
 }
 */
 
+void
 toqp(infile, outfile) 
 FILE *infile, *outfile;
 {
@@ -350,7 +360,7 @@ FILE *infile, *outfile;
     }
 }
 
-fromqp(infile, outfile, boundaries, boundaryct) 
+void fromqp(infile, outfile, boundaries, boundaryct) 
 FILE *infile, *outfile;
 char **boundaries;
 int *boundaryct;
