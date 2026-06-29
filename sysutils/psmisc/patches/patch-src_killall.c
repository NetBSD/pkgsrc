$NetBSD: patch-src_killall.c,v 1.1 2026/06/29 13:11:00 adam Exp $

Avoid non-portable getopt_long_only().

--- src/killall.c.orig	2024-03-03 10:57:39.000000000 +0000
+++ src/killall.c
@@ -940,7 +940,7 @@ main (int argc, char **argv)
 
 
     opterr = 0;
-    while ( (optc = getopt_long_only(argc,argv,"egy:o:ilqrs:u:vwZ:VIn:",options,NULL)) != -1) {
+    while ( (optc = getopt_long(argc,argv,"egy:o:ilqrs:u:vwZ:VIn:",options,NULL)) != -1) {
             switch (optc) {
             case 'e':
                 exact = 1;
