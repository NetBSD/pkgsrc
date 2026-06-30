$NetBSD: patch-canuum_termio.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

- Use const pointers for cached terminfo capability strings initialized
  by setupterm(3) since the strings are not modified and NetBSD exposes
  them as const
- Remove non-standard and unnecessary resetterm()

--- canuum/termio.c.orig	2003-12-27 17:15:21.000000000 +0000
+++ canuum/termio.c
@@ -51,15 +51,15 @@
 extern int putchar ();
 
 extern char Term_Name[];
-extern char *Term_UnderScoreStart;
-extern char *Term_UnderScoreEnd;
-extern char *Term_ClrScreen;
-extern char *Term_ClrEofLine;
-extern char *Term_ThrowCursor;
-extern char *Term_StandOutStart;
-extern char *Term_StandOutEnd;
-extern char *Term_BoldOutStart;
-extern char *Term_BoldOutEnd;
+extern const char *Term_UnderScoreStart;
+extern const char *Term_UnderScoreEnd;
+extern const char *Term_ClrScreen;
+extern const char *Term_ClrEofLine;
+extern const char *Term_ThrowCursor;
+extern const char *Term_StandOutStart;
+extern const char *Term_StandOutEnd;
+extern const char *Term_BoldOutStart;
+extern const char *Term_BoldOutEnd;
 static int bold_mode_fun = 0;
 
 int
@@ -175,7 +175,6 @@ openTermData ()
 void
 closeTermData ()
 {
-  resetterm ();
   reset_shell_mode ();
 }
 
