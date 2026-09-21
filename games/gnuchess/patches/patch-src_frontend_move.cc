$NetBSD: patch-src_frontend_move.cc,v 1.1 2026/09/21 09:30:53 wiz Exp $

Fix ctype(3) usage.
Mailed to bug-gnu-chess mailing list on 2026-09-21.

--- src/frontend/move.cc.orig	2026-09-21 08:50:44.746178707 +0000
+++ src/frontend/move.cc
@@ -559,7 +559,7 @@ leaf * ValidateMove (char *s, char *cleanMove)
    p = mvstr;
    do
    {
-      if (*s != 'x' && *s != '+' && *s != '=' && !isspace(*s))
+      if (*s != 'x' && *s != '+' && *s != '=' && !isspace((unsigned char)*s))
          *p++ = *s;
    } while (*s++ != '\0' );
 
