$NetBSD: patch-Wnn_uum_termcap.c,v 1.1 2011/09/13 07:23:19 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/termcap.c.orig	2002-06-13 21:27:47.000000000 +0000
+++ Wnn/uum/termcap.c
@@ -89,7 +89,7 @@ char *Term_UnderScoreEnd;
 
 char *Term_KeyPadOn;
 char *Term_KeyPadOff;
-#ifdef TERMCAP
+#if !HAVE_TERMINFO	/* Assume TERMCAP */
 char *Term_CursorNormal;
 char *Term_CursorInvisible;
 
@@ -564,4 +564,4 @@ strascii (dest, str)
   *dest = '\0';
 }
 
-#endif /* TERMCAP */
+#endif /* !HAVE_TERMINFO */
