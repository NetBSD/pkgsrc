$NetBSD: patch-src_lib_eina__strbuf.c,v 1.1 2011/12/05 17:14:52 joerg Exp $

--- src/lib/eina_strbuf.c.orig	2011-10-16 12:46:24.000000000 +0000
+++ src/lib/eina_strbuf.c
@@ -162,9 +162,9 @@ eina_strbuf_insert_vprintf(Eina_Strbuf *
 EAPI void
 eina_strbuf_trim(Eina_Strbuf *buf)
 {
-   char *c = buf->buf;
+   unsigned char *c = buf->buf;
 
-   while (buf->len > 0 && isspace(((unsigned char*)(buf->buf))[buf->len - 1]))
+   while (buf->len > 0 && isspace(c[buf->len - 1]))
      buf->len--;
    while (buf->len > 0 && isspace(*c))
      {
@@ -178,7 +178,7 @@ eina_strbuf_trim(Eina_Strbuf *buf)
 EAPI void
 eina_strbuf_ltrim(Eina_Strbuf *buf)
 {
-   char *c = buf->buf;
+   unsigned char *c = buf->buf;
 
    while (buf->len > 0 && isspace(*c))
      {
