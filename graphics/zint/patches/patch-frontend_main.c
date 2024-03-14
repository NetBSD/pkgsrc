$NetBSD: patch-frontend_main.c,v 1.1 2024/03/14 12:24:54 wiz Exp $

NetBSD does not support getopt_long_only.

--- frontend/main.c.orig	2024-03-14 12:03:48.639294632 +0000
+++ frontend/main.c
@@ -1443,7 +1443,7 @@ int main(int argc, char **argv) {
     win_args(&argc, &argv);
 #endif
 
-    opterr = 0; /* Disable `getopt_long_only()` printing errors */
+    opterr = 0; /* Disable `getopt_long()` printing errors */
     while (1) {
         enum options {
             OPT_ADDONGAP = 128, OPT_BATCH, OPT_BINARY, OPT_BG, OPT_BIND, OPT_BIND_TOP, OPT_BOLD, OPT_BORDER, OPT_BOX,
@@ -1542,7 +1542,7 @@ int main(int argc, char **argv) {
             {"whitesp", 1, NULL, 'w'},
             {NULL, 0, NULL, 0}
         };
-        const int c = getopt_long_only(argc, argv, "b:d:ehi:o:rtvw:", long_options, NULL);
+        const int c = getopt_long(argc, argv, "b:d:ehi:o:rtvw:", long_options, NULL);
         if (c == -1) break;
 
         switch (c) {
