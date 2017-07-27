$NetBSD: patch-src_rrd__graph.c,v 1.2 2017/07/27 18:31:20 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_graph.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_graph.c
@@ -1704,7 +1704,7 @@ static int strfduration(char * const des
             if ((zpad = *f == '0'))
                 f++;
 
-            if (isdigit(*f)) {
+            if (isdigit((unsigned char)*f)) {
                 int nread;
                 sscanf(f, "%d%n", &width, &nread);
                 f += nread;
