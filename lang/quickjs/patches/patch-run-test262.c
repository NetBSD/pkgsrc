$NetBSD: patch-run-test262.c,v 1.1 2022/01/30 10:55:03 he Exp $

Don't trigger undefined behaviour with isxxxxx() macros.

--- run-test262.c.orig	2021-03-27 10:00:32.000000000 +0000
+++ run-test262.c
@@ -1635,7 +1635,7 @@ int run_test(const char *filename, int i
                 /* XXX: should extract the phase */
                 char *q = find_tag(p, "type:", &state);
                 if (q) {
-                    while (isspace(*q))
+                    while (isspace((unsigned char)*q))
                         q++;
                     error_type = strdup_len(q, strcspn(q, " \n"));
                 }
@@ -2025,7 +2025,7 @@ int main(int argc, char **argv)
     update_exclude_dirs();
 
     if (is_dir_list) {
-        if (optind < argc && !isdigit(argv[optind][0])) {
+        if (optind < argc && !isdigit((unsigned char)argv[optind][0])) {
             filename = argv[optind++];
             namelist_load(&test_list, filename);
         }
