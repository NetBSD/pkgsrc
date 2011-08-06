$NetBSD: patch-htop.c,v 1.1 2011/08/06 16:36:41 cheusov Exp $

--- htop.c.orig	2010-11-24 18:45:38.000000000 +0000
+++ htop.c
@@ -272,7 +272,7 @@ int main(int argc, char** argv) {
       setlocale(LC_CTYPE, getenv("LC_ALL"));
 
    /* Parse arguments */
-   while ((opt = getopt_long_only(argc, argv, "hvCs:d:u:", long_opts, &opti))) {
+   while ((opt = getopt_long(argc, argv, "hvCs:d:u:", long_opts, &opti))) {
       if (opt == EOF) break;
       switch (opt) {
          case 'h':
