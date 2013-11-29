$NetBSD: patch-curses__helpers.c,v 1.2 2013/11/29 23:13:56 dholland Exp $

Fix printf format strings.

--- curses_helpers.c.orig	2013-09-10 11:42:25.000000000 +0000
+++ curses_helpers.c
@@ -458,7 +458,7 @@ combo_entry(WINDOW *list_win, Etree *ite
 		snprintf(buf, MAXLEN, "[ %-15s%c%c]", tmp_entry, tbi, status);
 		entry_size = strlen(buf);
 		wattron(list_win, A_BOLD);
-		wprintw(list_win, buf);
+		wprintw(list_win, "%s", buf);
 		wattroff(list_win, A_BOLD);
 	}
 	/* then comment | item list */
@@ -653,11 +653,11 @@ progress_bar(const char **keylist, char 
 	for (i = 0; i < pg; i++) {
 		/* clear line */
 		line_padding(buf, ' ', w);
-		mvwprintw(popup, 1, 2, buf);
+		mvwprintw(popup, 1, 2, "%s", buf);
 		trimcr(key);
 		cut_str(key, w - 3);
 		line_padding(key, ' ', w);
-		mvwprintw(popup, 1, 2, key);
+		mvwprintw(popup, 1, 2, "%s", key);
 		wattron(popup, A_REVERSE);
 		mvwprintw(popup, 3, i + 2, " ");
 		wattroff(popup, A_REVERSE);
@@ -698,7 +698,7 @@ cmd_spawn(int waitkey, const char **prog
 	while (fgets(buf, MAXLEN, fp) != NULL) {
 		/* shell output preferred instead of progress bars */
 		if (conf.shell_output)
-			printf(buf);
+			printf("%s", buf);
 		else
 			if (next)
 				next = progress_bar(progress_list, 
