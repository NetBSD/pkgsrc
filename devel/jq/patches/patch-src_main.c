$NetBSD: patch-src_main.c,v 1.3 2026/06/28 15:41:12 wiz Exp $

ctype(3) usage
https://github.com/jqlang/jq/issues/3569

--- src/main.c.orig	2026-06-23 06:02:47.113070826 +0000
+++ src/main.c
@@ -437,7 +437,7 @@ int main(int argc, char* argv[]) {
           errno = 0;
           long indent = strtol(argv[i+1], &end, 10);
           if (errno || indent < -1 || indent > 7 ||
-              isspace(*argv[i+1]) || end == argv[i+1] || *end) {
+              isspace((unsigned char)*argv[i+1]) || end == argv[i+1] || *end) {
             fprintf(stderr, "jq: --indent takes a number between -1 and 7\n");
             die();
           }
