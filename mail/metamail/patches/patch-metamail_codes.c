$NetBSD: patch-metamail_codes.c,v 1.1 2012/10/26 20:27:15 joerg Exp $

--- metamail/codes.c.orig	2012-10-25 19:39:57.000000000 +0000
+++ metamail/codes.c
@@ -174,7 +174,7 @@ int PortableNewlines;
 }
 #endif
 
-from64(infile, outfile, boundaries, boundaryct, PortableNewlines) 
+void from64(infile, outfile, boundaries, boundaryct, PortableNewlines) 
 FILE *infile, *outfile;
 char **boundaries;
 int *boundaryct;
@@ -350,7 +350,7 @@ FILE *infile, *outfile;
     }
 }
 
-fromqp(infile, outfile, boundaries, boundaryct) 
+void fromqp(infile, outfile, boundaries, boundaryct) 
 FILE *infile, *outfile;
 char **boundaries;
 int *boundaryct;
