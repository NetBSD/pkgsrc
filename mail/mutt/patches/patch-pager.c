$NetBSD: patch-pager.c,v 1.1 2025/08/25 11:29:53 wiz Exp $

Fix ctype(3) usage.
https://gitlab.com/muttmua/mutt/-/issues/508

--- pager.c.orig	2025-08-25 11:26:35.247435070 +0000
+++ pager.c
@@ -1011,7 +1011,7 @@ resolve_types (char *buf, char *raw, str
 
 static int is_ansi (const char *buf)
 {
-  while (*buf && (isdigit(*buf) || *buf == ';'))
+  while (*buf && (isdigit((unsigned char)*buf) || *buf == ';'))
     buf++;
   return (*buf == 'm');
 }
