$NetBSD: patch-sgetopt.c,v 1.1 2025/06/27 17:27:41 schmonz Exp $

Avoid "conflicting types for 'sgetoptmine'" on Illumos.

--- sgetopt.c.orig	2016-03-29 19:44:38.000000000 +0000
+++ sgetopt.c
@@ -25,7 +25,7 @@ Documentation in sgetopt.3.
 int opterr = 1;
 char *optprogname = 0;
 
-int getopt(int argc,char **argv,char *opts)
+int getopt(int argc, char * const* argv, const char *opts)
 {
   int c;
   char *s;
