$NetBSD: patch-curses__helpers.c,v 1.3 2017/12/29 11:59:13 plunky Exp $

fix -Wset-but-unused
Fix printf format strings.

--- curses_helpers.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ curses_helpers.c
@@ -393,7 +393,7 @@ static int
 combo_entry(WINDOW *list_win, Etree *item, HL_datas *hl, 
 	    int d_index, int y, const char *path) {
 
-	int i, real_hl;
+	int i;
 	int sb_real, sb_y;
 	int entry_size, comment_size;
 	static int last_sb = -1;
@@ -416,7 +416,6 @@ combo_entry(WINDOW *list_win, Etree *ite
 	}
 	
 	/* highlight*/
-	real_hl = hl->hl_index + hl->top_line;
 	/* delta between hl and old */
 	delta = hl->old_index - hl->hl_index;
 	
@@ -458,7 +457,7 @@ combo_entry(WINDOW *list_win, Etree *ite
 		snprintf(buf, MAXLEN, "[ %-15s%c%c]", tmp_entry, tbi, status);
 		entry_size = strlen(buf);
 		wattron(list_win, A_BOLD);
-		wprintw(list_win, buf);
+		wprintw(list_win, "%s", buf);
 		wattroff(list_win, A_BOLD);
 	}
 	/* then comment | item list */
@@ -653,11 +652,11 @@ progress_bar(const char **keylist, char 
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
@@ -698,7 +697,7 @@ cmd_spawn(int waitkey, const char **prog
 	while (fgets(buf, MAXLEN, fp) != NULL) {
 		/* shell output preferred instead of progress bars */
 		if (conf.shell_output)
-			printf(buf);
+			printf("%s", buf);
 		else
 			if (next)
 				next = progress_bar(progress_list, 
