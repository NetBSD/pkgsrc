$NetBSD: patch-src_rrd__graph.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_graph.c~	2016-04-19 15:52:25.000000000 +0000
+++ src/rrd_graph.c
@@ -1704,7 +1704,7 @@ static int strfduration(char * const des
             if ((zpad = *f == '0'))
                 f++;
 
-            if (isdigit(*f)) {
+            if (isdigit((unsigned char)*f)) {
                 int nread;
                 sscanf(f, "%d%n", &width, &nread);
                 f += nread;
