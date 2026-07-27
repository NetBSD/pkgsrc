$NetBSD: patch-http.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- http.c.orig	2010-09-19 20:51:53.000000000 +0000
+++ http.c
@@ -89,7 +89,7 @@ FILE *http_get_stream(int fd, int *code) {
  */
 FILE *http_get_stream(int fd, int *code) {
     FILE *f = fdopen(fd, "r");
-    char buf[256];
+    char buf[256 + 4];
     char *p;
 
     if (fgets(buf, sizeof(buf), f) == NULL || memcmp(buf, "HTTP/1", 6) != 0
@@ -160,7 +160,7 @@ char *referer;
  * Sets the proxy settings for HTTP connections to use; these can be either as
  * a host[:port] or as http://host[:port].
  * Returns non-zero if the settings were obtained successfully. */
-int set_proxy_from_string(const char *s) {
+int set_proxy_from_string(char *s) {
     if (!memcmp(s, http_scheme, strlen(http_scheme))) {
         /* http:// style proxy string */
         proxy = malloc(256);
@@ -539,11 +539,12 @@ struct range_fetch {
  * Set up a range_fetch to fetch from a given URL. Private method. 
  * C is a nightmare for memory allocation here. At least the errors should be
  * caught, but minor memory leaks may occur on some error paths. */
-static int range_fetch_set_url(struct range_fetch* rf, const char* orig_url) {
+static int range_fetch_set_url(struct range_fetch* rf, char* orig_url) {
     /* Get the host, port and path from the URL. */
-    char hostn[sizeof(rf->hosth)];
+    unsigned int hostnsz = sizeof(rf->hosth) - 4;
+    char hostn[hostnsz];
     char* cport;
-    char* p = get_http_host_port(orig_url, hostn, sizeof(hostn), &cport);
+    char* p = get_http_host_port(orig_url, hostn, hostnsz, &cport);
     if (!p) {
         return 0;
     }
@@ -658,7 +659,7 @@ static char *rfgets(char *buf, size_t len, struct rang
 /* range_fetch_start(origin_url)
  * Returns a new range fetch object, for the given URL.
  */
-struct range_fetch *range_fetch_start(const char *orig_url) {
+struct range_fetch *range_fetch_start(char *orig_url) {
     struct range_fetch *rf = malloc(sizeof(struct range_fetch));
     if (!rf)
         return NULL;
