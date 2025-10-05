$NetBSD: patch-sed_compile.c,v 1.1 2025/10/05 11:59:43 js Exp $

Fix "error: #pragma GCC diagnostic not allowed inside functions"

--- sed/compile.c.orig	2022-10-23 17:52:23.000000000 +0000
+++ sed/compile.c
@@ -198,17 +198,17 @@ static struct output *file_read = NULL;
 static struct output *file_write = NULL;
 
 /* Complain about an unknown command and exit. */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 static void
 bad_command (char ch)
 {
   const char *msg = _(UNKNOWN_CMD);
   char *unknown_cmd = xmalloc (strlen (msg));
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wformat-nonliteral"
   sprintf (unknown_cmd, msg, ch);
-#pragma GCC diagnostic pop
   bad_prog (unknown_cmd);
 }
+#pragma GCC diagnostic pop
 
 /* Complain about a programming error and exit. */
 void
