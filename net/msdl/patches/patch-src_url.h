$NetBSD: patch-src_url.h,v 1.1 2012/12/25 21:03:36 joerg Exp $

--- src/url.h.orig	2012-12-25 14:09:52.000000000 +0000
+++ src/url.h
@@ -60,7 +60,7 @@ struct url_t {
 struct url_t *new_url_t(const char *url);
 void free_url_t(struct url_t *u);
 void copy_url_t(struct url_t *url,struct url_t *srcurl);
-inline int is_url_valid_char(int c);
+int is_url_valid_char(int c);
 void url_unescape_string(char *dst,char *src);
 
 
