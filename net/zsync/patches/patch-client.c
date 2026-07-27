$NetBSD: patch-client.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- client.c.orig	2010-09-19 20:51:53.000000000 +0000
+++ client.c
@@ -59,7 +59,7 @@ FILE* open_zcat_pipe(const char* fname)
         int i, j;
 
         for (i = 0, j = 5; fname[i]; i++) {
-            if (!isalnum(fname[i]))
+            if (!isalnum((unsigned char)(fname[i])))
                 cmd[j++] = '\\';
             cmd[j++] = fname[i];
         }
@@ -146,7 +146,7 @@ long long http_down;
  * number of entries is passed by reference and updated in place. The new entry
  * is appended to the list.
  */
-static void **append_ptrlist(int *n, void **p, void *a) {
+static char **append_ptrlist(int *n, char **p, void *a) {
     if (!a)
         return p;
     p = realloc(p, (*n + 1) * sizeof *p);
@@ -217,7 +217,7 @@ static char *get_filename_prefix(const char *p) {
     else
         t = s;
     u = t;
-    while (isalnum(*u)) {
+    while (isalnum((unsigned char)(*u))) {
         u++;
     }
     *u = 0;
@@ -392,7 +392,7 @@ int fetch_remaining_blocks(struct zsync_state *zs) {
  */
 int fetch_remaining_blocks(struct zsync_state *zs) {
     int n, utype;
-    const char *const *url = zsync_get_urls(zs, &n, &utype);
+    char **url = zsync_get_urls(zs, &n, &utype);
     int *status;        /* keep status for each URL - 0 means no error */
     int ok_urls = n;
 
