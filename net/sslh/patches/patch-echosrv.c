$NetBSD: patch-echosrv.c,v 1.1 2013/11/08 13:33:55 obache Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- echosrv.c.orig	2013-07-27 14:25:04.000000000 +0000
+++ echosrv.c
@@ -64,7 +64,7 @@ void parse_cmdline(int argc, char* argv[
     };
     struct addrinfo **a;
 
-    while ((c = getopt_long_only(argc, argv, "l:p:", options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, "l:p:", options, NULL)) != -1) {
         if (c == 0) continue;
 
         switch (c) {
