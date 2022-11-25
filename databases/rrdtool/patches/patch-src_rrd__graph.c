$NetBSD: patch-src_rrd__graph.c,v 1.3 2022/11/25 10:41:15 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_graph.c.orig	2022-03-14 14:30:12.000000000 +0000
+++ src/rrd_graph.c
@@ -1735,7 +1735,7 @@ static int strfduration(
                 if ((zpad = *f == '0'))
                     f++;
 
-                if (isdigit(*f)) {
+                if (isdigit((unsigned char)*f)) {
                     int       nread;
 
                     sscanf(f, "%d%n", &width, &nread);
