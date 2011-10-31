$NetBSD: patch-src_primer3__boulder__main.c,v 1.1.1.1 2011/10/31 21:25:57 brook Exp $

getopt_long_only is not very portable; use getopt_long instead.

--- src/primer3_boulder_main.c.orig	2010-07-08 17:58:25.000000000 +0000
+++ src/primer3_boulder_main.c
@@ -133,7 +133,7 @@ main(int argc, char *argv[]) 
   
   /* Read in the flags provided with the program call */
   opterr = 0;
-  while ((opt = getopt_long_only(argc, argv, "", long_options, &option_index)) != -1) {
+  while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) != -1) {
     switch (opt) {
     case 'a':
       about = 1;
