$NetBSD: patch-src_primer3__boulder__main.c,v 1.2 2015/01/31 06:18:43 mef Exp $

getopt_long_only is not very portable; use getopt_long instead.

--- src/primer3_boulder_main.c.orig	2013-10-21 16:49:57.000000000 +0900
+++ src/primer3_boulder_main.c	2015-01-31 15:12:56.000000000 +0900
@@ -128,7 +128,7 @@ main(int argc, char *argv[])
 
   /* Read in the flags provided with the program call */
   opterr = 0;
-  while ((opt = getopt_long_only(argc, argv, "", long_options, &option_index)) != -1) {
+  while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) != -1) {
     switch (opt) {
     case 'a':
       about = 1;
