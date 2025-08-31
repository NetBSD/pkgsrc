$NetBSD: patch-src_tty__interface.c,v 1.1 2025/08/31 10:19:45 leot Exp $

Fix ctype(3) abuse

--- src/tty_interface.c.orig	2025-08-31 10:16:28.393716776 +0000
+++ src/tty_interface.c
@@ -170,10 +170,10 @@ static void action_del_word(tty_interfac
 	size_t original_cursor = state->cursor;
 	size_t cursor = state->cursor;
 
-	while (cursor && isspace(state->search[cursor - 1]))
+	while (cursor && isspace((unsigned char)state->search[cursor - 1]))
 		cursor--;
 
-	while (cursor && !isspace(state->search[cursor - 1]))
+	while (cursor && !isspace((unsigned char)state->search[cursor - 1]))
 		cursor--;
 
 	memmove(&state->search[cursor], &state->search[original_cursor], strlen(state->search) - original_cursor + 1);
