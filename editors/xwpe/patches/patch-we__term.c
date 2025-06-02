$NetBSD: patch-we__term.c,v 1.1 2025/06/02 12:54:30 vins Exp $

Add missing prototype.

--- we_term.c.orig	2025-06-02 11:48:21.918716495 +0000
+++ we_term.c
@@ -97,6 +97,8 @@ char *tgoto();
 #endif
 #endif
 
+int WpeGpmMouseInit(void);
+
 int WpeDllInit(int *argc, char **argv)
 {
  fk_u_cursor = fk_t_cursor;
