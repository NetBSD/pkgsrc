$NetBSD: patch-parse_extract.c,v 1.1 2025/05/05 10:04:03 wiz Exp $

Fix ctype(3) arguments
https://github.com/neomutt/neomutt/issues/4620

--- parse/extract.c.orig	2025-05-05 09:51:07.682959138 +0000
+++ parse/extract.c
@@ -62,7 +62,7 @@ int parse_extract_token(struct Buffer *d
   {
     if (qc == '\0')
     {
-      if (isspace(ch) && !(flags & TOKEN_SPACE))
+      if (isspace((unsigned char)ch) && !(flags & TOKEN_SPACE))
         break;
       if ((ch == '#') && !(flags & TOKEN_COMMENT))
         break;
