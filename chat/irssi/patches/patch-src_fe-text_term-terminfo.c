$NetBSD: patch-src_fe-text_term-terminfo.c,v 1.1 2020/05/18 18:38:31 maya Exp $

Fix hang when pressing ctrl+space.
From https://github.com/irssi/irssi/issues/1180

--- src/fe-text/term-terminfo.c.orig	2019-08-29 13:48:46.000000000 +0000
+++ src/fe-text/term-terminfo.c
@@ -674,6 +674,10 @@ static int input_utf8(const unsigned cha
 {
 	unichar c = g_utf8_get_char_validated((char *)buffer, size);
 
+	/* GLib >= 2.63 do not accept Unicode NUL anymore */
+	if (c == (unichar) -2 && *buffer == 0 && size > 0)
+		c = 0;
+
 	switch (c) {
 	case (unichar)-1:
 		/* not UTF8 - fallback to 8bit ascii */
