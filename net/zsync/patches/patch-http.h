$NetBSD: patch-http.h,v 1.1 2026/07/27 15:38:30 ryoon Exp $

--- http.h.orig	2010-09-16 17:17:49.000000000 +0000
+++ http.h
@@ -18,13 +18,13 @@ extern char *referer;
 
 extern char *referer;
 
-int set_proxy_from_string(const char* s);
+int set_proxy_from_string(char* s);
 
 FILE* http_get(const char* orig_url, char** track_referer, const char* tfname);
 
 struct range_fetch;
 
-struct range_fetch* range_fetch_start(const char* orig_url);
+struct range_fetch* range_fetch_start(char* orig_url);
 void range_fetch_addranges(struct range_fetch* rf, off_t* ranges, int nranges);
 int get_range_block(struct range_fetch* rf, off_t* offset, unsigned char* data, size_t dlen);
 off_t range_fetch_bytes_down(const struct range_fetch* rf);
