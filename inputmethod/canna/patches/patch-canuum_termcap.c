$NetBSD: patch-canuum_termcap.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

- Use const pointers for cached terminfo capability strings initialized
  by setupterm(3) since the strings are not modified and NetBSD exposes
  them as const

--- canuum/termcap.c.orig	2026-06-29 03:58:12.628641986 +0000
+++ canuum/termcap.c
@@ -63,24 +63,24 @@ int Term_RowWidth;
 /*
 char    *Term_Bell;
 */
-char *Term_ClrScreen;
-char *Term_ClrEofLine;
-char *Term_CleEndScreen;
-char *Term_ThrowCursor;
-char *Term_StandOutStart;       /* These variables has value even if terminfo is used. see termio.c. */
-char *Term_StandOutEnd;
+const char *Term_ClrScreen;
+const char *Term_ClrEofLine;
+const char *Term_CleEndScreen;
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
 
-char *Term_KeyPadOn;
-char *Term_KeyPadOff;
+const char *Term_KeyPadOn;
+const char *Term_KeyPadOff;
 #ifdef TERMCAP
 char *Term_CursorNormal;
 char *Term_CursorInvisible;
