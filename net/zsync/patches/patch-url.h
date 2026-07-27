$NetBSD: patch-url.h,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- url.h.orig	2026-07-27 14:31:08.787889570 +0000
+++ url.h
@@ -20,7 +20,7 @@ extern const char http_scheme[];
  * and, if present, return a (malloced) string buffer containing the port string.
  * Or return NULL if not HTTP or other parsing failure.
  */
-char* get_http_host_port(const char* url, char* hostn, int hnlen, char** port);
+char* get_http_host_port(char* url, char* hostn, int hnlen, char** port);
 
 char* __attribute__((pure)) make_url_absolute(const char* base, const char* url);
 
