$NetBSD: patch-url.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- url.c.orig	2026-07-27 14:30:13.132895329 +0000
+++ url.c
@@ -36,7 +36,7 @@ const char http_scheme[] = { "http://" };
  * return value is the path part of the URL, a malloced string.
  * Or return value NULL on failure (host and port could have been written to).
  */
-char *get_http_host_port(const char *url, char *hostn, int hnlen, char **port) {
+char *get_http_host_port(char *url, char *hostn, int hnlen, char **port) {
     char *p, *q;
 
     /* Check it's HTTP */
