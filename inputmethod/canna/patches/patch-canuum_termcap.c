$NetBSD: patch-canuum_termcap.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Appease warnings.

--- canuum/termcap.c.orig	2004-04-26 21:48:37.000000000 +0000
+++ canuum/termcap.c
@@ -64,21 +64,21 @@ int Term_RowWidth;
 /*
 char    *Term_Bell;
 */
-char *Term_ClrScreen;
-char *Term_ClrEofLine;
+const char *Term_ClrScreen;
+const char *Term_ClrEofLine;
 char *Term_CleEndScreen;
-char *Term_ThrowCursor;
-char *Term_StandOutStart;       /* These variables has value even if terminfo is used. see termio.c. */
-char *Term_StandOutEnd;
+const char *Term_ThrowCursor;
+const char *Term_StandOutStart;       /* These variables has value even if terminfo is used. see termio.c. */
+const char *Term_StandOutEnd;
 static int bold_mode_fun;
-char *Term_BoldOutStart;
-char *Term_BoldOutEnd;
+const char *Term_BoldOutStart;
+const char *Term_BoldOutEnd;
 /*
 int     Term_StandOutBlankNum;
 char    *Term_DelChar;
 */
-char *Term_UnderScoreStart;
-char *Term_UnderScoreEnd;
+const char *Term_UnderScoreStart;
+const char *Term_UnderScoreEnd;
 
 char *Term_KeyPadOn;
 char *Term_KeyPadOff;
