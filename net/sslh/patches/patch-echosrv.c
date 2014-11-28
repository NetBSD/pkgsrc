$NetBSD: patch-echosrv.c,v 1.2 2014/11/28 10:45:28 bsiegert Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- echosrv.c.orig	2014-02-11 21:06:01.000000000 +0000
+++ echosrv.c
@@ -64,7 +64,7 @@ void parse_cmdline(int argc, char* argv[
     };
     struct addrinfo **a;
 
-    while ((c = getopt_long_only(argc, argv, "l:p:", options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, "l:p:", options, NULL)) != -1) {
         if (c == 0) continue;
 
         switch (c) {
