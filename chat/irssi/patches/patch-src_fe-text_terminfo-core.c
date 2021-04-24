$NetBSD: patch-src_fe-text_terminfo-core.c,v 1.2 2021/04/24 08:36:22 nia Exp $

Fix compatibility with NetBSD curses

from the ncurses man page:

>X/Open  Curses  prototypes tparm with a fixed number of parameters,
>rather than a variable argument list.

>This implementation uses a variable argument list, but can be  con-
>figured  to  use  the  fixed-parameter list.  Portable applications
>should provide 9 parameters after the format; zeroes are  fine  for
>this purpose.

>In  response  to review comments by Thomas E. Dickey, X/Open Curses
>Issue 7 proposed the tiparm function in mid-2009.

Previously, irssi defined its own tparm prototype, so passing
a variable number of arguments worked.

However, since this change:

https://github.com/irssi/irssi/commit/0b82f14151dad5f106c208d25818816a8f782a54

<term.h> in included, which on systems using NetBSD libcurses, gives
the X/Open compliant definition of tparm, which does not work with
a variable number of arguments.

https://github.com/irssi/irssi/pull/1305

--- src/fe-text/terminfo-core.c.orig	2021-04-08 14:42:39.000000000 +0000
+++ src/fe-text/terminfo-core.c
@@ -17,7 +17,7 @@ inline static int term_putchar(int c)
 #else
 /* Don't bother including curses.h because of these -
    they might not even be defined there */
-char *tparm();
+char *tiparm();
 int tputs();
 
 int setupterm();
@@ -110,14 +110,14 @@ static TERMINFO_REC tcaps[] = {
 /* Move cursor (cursor_address / cup) */
 static void _move_cup(TERM_REC *term, int x, int y)
 {
-	tput(tparm(term->TI_cup, y, x));
+	tput(tiparm(term->TI_cup, y, x));
 }
 
 /* Move cursor (column_address+row_address / hpa+vpa) */
 static void _move_pa(TERM_REC *term, int x, int y)
 {
-	tput(tparm(term->TI_hpa, x));
-	tput(tparm(term->TI_vpa, y));
+	tput(tiparm(term->TI_hpa, x));
+	tput(tiparm(term->TI_vpa, y));
 }
 
 /* Move cursor from a known position */
@@ -133,38 +133,38 @@ static void _move_relative(TERM_REC *ter
 	if (oldx > 0 && y == oldy) {
                 /* move cursor left/right */
 		if (x == oldx-1 && term->TI_cub1) {
-			tput(tparm(term->TI_cub1));
+			tput(tiparm(term->TI_cub1));
                         return;
 		}
 		if (x == oldx+1 && y == oldy && term->TI_cuf1) {
-			tput(tparm(term->TI_cuf1));
+			tput(tiparm(term->TI_cuf1));
                         return;
 		}
 	}
 
         /* fallback to absolute positioning */
 	if (term->TI_cup) {
-		tput(tparm(term->TI_cup, y, x));
+		tput(tiparm(term->TI_cup, y, x));
                 return;
 	}
 
 	if (oldy != y)
-		tput(tparm(term->TI_vpa, y));
+		tput(tiparm(term->TI_vpa, y));
         if (oldx != x)
-		tput(tparm(term->TI_hpa, x));
+		tput(tiparm(term->TI_hpa, x));
 }
 
 /* Set cursor visible/invisible */
 static void _set_cursor_visible(TERM_REC *term, int set)
 {
-	tput(tparm(set ? term->TI_cnorm : term->TI_civis));
+	tput(tiparm(set ? term->TI_cnorm : term->TI_civis));
 }
 
 #define scroll_region_setup(term, y1, y2) \
 	if ((term)->TI_csr != NULL) \
-		tput(tparm((term)->TI_csr, y1, y2)); \
+		tput(tiparm((term)->TI_csr, y1, y2)); \
 	else if ((term)->TI_wind != NULL) \
-		tput(tparm((term)->TI_wind, y1, y2, 0, (term)->width-1));
+		tput(tiparm((term)->TI_wind, y1, y2, 0, (term)->width-1));
 
 /* Scroll (change_scroll_region+parm_rindex+parm_index / csr+rin+indn) */
 static void _scroll_region(TERM_REC *term, int y1, int y2, int count)
@@ -175,10 +175,10 @@ static void _scroll_region(TERM_REC *ter
 	term->move(term, 0, y1);
 	if (count > 0) {
 		term->move(term, 0, y2);
-		tput(tparm(term->TI_indn, count, count));
+		tput(tiparm(term->TI_indn, count, count));
 	} else if (count < 0) {
 		term->move(term, 0, y1);
-		tput(tparm(term->TI_rin, -count, -count));
+		tput(tiparm(term->TI_rin, -count, -count));
 	}
 
         /* reset the scrolling region to full screen */
@@ -196,11 +196,11 @@ static void _scroll_region_1(TERM_REC *t
 	if (count > 0) {
 		term->move(term, 0, y2);
 		for (i = 0; i < count; i++)
-			tput(tparm(term->TI_ind));
+			tput(tiparm(term->TI_ind));
 	} else if (count < 0) {
 		term->move(term, 0, y1);
 		for (i = count; i < 0; i++)
-			tput(tparm(term->TI_ri));
+			tput(tiparm(term->TI_ri));
 	}
 
         /* reset the scrolling region to full screen */
@@ -217,14 +217,14 @@ static void _scroll_line(TERM_REC *term,
 
 	if (count > 0) {
 		term->move(term, 0, y1);
-		tput(tparm(term->TI_dl, count, count));
+		tput(tiparm(term->TI_dl, count, count));
 		term->move(term, 0, y2-count+1);
-		tput(tparm(term->TI_il, count, count));
+		tput(tiparm(term->TI_il, count, count));
 	} else if (count < 0) {
 		term->move(term, 0, y2+count+1);
-		tput(tparm(term->TI_dl, -count, -count));
+		tput(tiparm(term->TI_dl, -count, -count));
 		term->move(term, 0, y1);
-		tput(tparm(term->TI_il, -count, -count));
+		tput(tiparm(term->TI_il, -count, -count));
 	}
 
         /* reset the scrolling region to full screen */
@@ -239,38 +239,38 @@ static void _scroll_line_1(TERM_REC *ter
 	if (count > 0) {
 		term->move(term, 0, y1);
                 for (i = 0; i < count; i++)
-			tput(tparm(term->TI_dl1));
+			tput(tiparm(term->TI_dl1));
 		term->move(term, 0, y2-count+1);
                 for (i = 0; i < count; i++)
-			tput(tparm(term->TI_il1));
+			tput(tiparm(term->TI_il1));
 	} else if (count < 0) {
 		term->move(term, 0, y2+count+1);
 		for (i = count; i < 0; i++)
-			tput(tparm(term->TI_dl1));
+			tput(tiparm(term->TI_dl1));
 		term->move(term, 0, y1);
 		for (i = count; i < 0; i++)
-			tput(tparm(term->TI_il1));
+			tput(tiparm(term->TI_il1));
 	}
 }
 
 /* Clear screen (clear_screen / clear) */
 static void _clear_screen(TERM_REC *term)
 {
-	tput(tparm(term->TI_clear));
+	tput(tiparm(term->TI_clear));
 }
 
 /* Clear screen (clr_eos / ed) */
 static void _clear_eos(TERM_REC *term)
 {
         term->move(term, 0, 0);
-	tput(tparm(term->TI_ed));
+	tput(tiparm(term->TI_ed));
 }
 
 /* Clear screen (parm_delete_line / dl) */
 static void _clear_del(TERM_REC *term)
 {
         term->move(term, 0, 0);
-	tput(tparm(term->TI_dl, term->height, term->height));
+	tput(tiparm(term->TI_dl, term->height, term->height));
 }
 
 /* Clear screen (delete_line / dl1) */
@@ -280,19 +280,19 @@ static void _clear_del_1(TERM_REC *term)
 
 	term->move(term, 0, 0);
         for (i = 0; i < term->height; i++)
-		tput(tparm(term->TI_dl1));
+		tput(tiparm(term->TI_dl1));
 }
 
 /* Clear to end of line (clr_eol / el) */
 static void _clrtoeol(TERM_REC *term)
 {
-	tput(tparm(term->TI_el));
+	tput(tiparm(term->TI_el));
 }
 
 /* Repeat character (rep / rp) */
 static void _repeat(TERM_REC *term, char chr, int count)
 {
-	tput(tparm(term->TI_rep, chr, count));
+	tput(tiparm(term->TI_rep, chr, count));
 }
 
 /* Repeat character (manual) */
@@ -307,42 +307,42 @@ static void _repeat_manual(TERM_REC *ter
 /* Reset all terminal attributes */
 static void _set_normal(TERM_REC *term)
 {
-	tput(tparm(term->TI_normal));
+	tput(tiparm(term->TI_normal));
 }
 
 static void _set_blink(TERM_REC *term)
 {
-	tput(tparm(term->TI_blink));
+	tput(tiparm(term->TI_blink));
 }
 
 /* Reverse on */
 static void _set_reverse(TERM_REC *term)
 {
-	tput(tparm(term->TI_rev));
+	tput(tiparm(term->TI_rev));
 }
 
 /* Bold on */
 static void _set_bold(TERM_REC *term)
 {
-	tput(tparm(term->TI_bold));
+	tput(tiparm(term->TI_bold));
 }
 
 /* Underline on/off */
 static void _set_uline(TERM_REC *term, int set)
 {
-	tput(tparm(set ? term->TI_smul : term->TI_rmul));
+	tput(tiparm(set ? term->TI_smul : term->TI_rmul));
 }
 
 /* Standout on/off */
 static void _set_standout(TERM_REC *term, int set)
 {
-	tput(tparm(set ? term->TI_smso : term->TI_rmso));
+	tput(tiparm(set ? term->TI_smso : term->TI_rmso));
 }
 
 /* Italic on/off */
 static void _set_italic(TERM_REC *term, int set)
 {
-	tput(tparm(set ? term->TI_sitm : term->TI_ritm));
+	tput(tiparm(set ? term->TI_sitm : term->TI_ritm));
 }
 
 /* Standout on (fallback for reverse) */
@@ -367,19 +367,19 @@ inline static int color256(const TERM_RE
 /* Change foreground color */
 static void _set_fg(TERM_REC *term, int color)
 {
-	tput(tparm(term->TI_fg[color256(term, color)]));
+	tput(tiparm(term->TI_fg[color256(term, color)]));
 }
 
 /* Change background color */
 static void _set_bg(TERM_REC *term, int color)
 {
-	tput(tparm(term->TI_bg[color256(term, color)]));
+	tput(tiparm(term->TI_bg[color256(term, color)]));
 }
 
 /* Beep */
 static void _beep(TERM_REC *term)
 {
-	tput(tparm(term->TI_bel));
+	tput(tiparm(term->TI_bel));
 }
 
 static void _ignore(TERM_REC *term)
@@ -393,7 +393,7 @@ static void _ignore_parm(TERM_REC *term,
 static void terminfo_set_appkey_mode(TERM_REC *term, int set)
 {
 	if (term->TI_smkx && term->TI_rmkx)
-		tput(tparm(set ? term->TI_smkx : term->TI_rmkx));
+		tput(tiparm(set ? term->TI_smkx : term->TI_rmkx));
 }
 
 static void term_dec_set_bracketed_paste_mode(int enable)
@@ -478,11 +478,11 @@ void terminfo_setup_colors(TERM_REC *ter
 	if (term->TI_setaf) {
 		for (i = 0; i < term->TI_colors; i++) {
 			color = i < 16 ? ansitab[i] : i;
-			term->TI_fg[i] = g_strdup(tparm(term->TI_setaf, color, 0));
+			term->TI_fg[i] = g_strdup(tiparm(term->TI_setaf, color, 0));
 		}
 	} else if (term->TI_setf) {
 		for (i = 0; i < term->TI_colors; i++)
-                        term->TI_fg[i] = g_strdup(tparm(term->TI_setf, i, 0));
+                        term->TI_fg[i] = g_strdup(tiparm(term->TI_setf, i, 0));
 	} else if (force) {
 		for (i = 0; i < 8; i++)
                         term->TI_fg[i] = g_strdup_printf("\033[%dm", 30+ansitab[i]);
@@ -491,11 +491,11 @@ void terminfo_setup_colors(TERM_REC *ter
 	if (term->TI_setab) {
 		for (i = 0; i < term->TI_colors; i++) {
 			color = i < 16 ? ansitab[i] : i;
-			term->TI_bg[i] = g_strdup(tparm(term->TI_setab, color, 0));
+			term->TI_bg[i] = g_strdup(tiparm(term->TI_setab, color, 0));
 		}
 	} else if (term->TI_setb) {
 		for (i = 0; i < term->TI_colors; i++)
-                        term->TI_bg[i] = g_strdup(tparm(term->TI_setb, i, 0));
+                        term->TI_bg[i] = g_strdup(tiparm(term->TI_setb, i, 0));
 	} else if (force) {
 		for (i = 0; i < 8; i++)
                         term->TI_bg[i] = g_strdup_printf("\033[%dm", 40+ansitab[i]);
@@ -539,7 +539,7 @@ static void terminfo_input_deinit(TERM_R
 void terminfo_cont(TERM_REC *term)
 {
 	if (term->TI_smcup)
-		tput(tparm(term->TI_smcup));
+		tput(tiparm(term->TI_smcup));
 
 	if (term->appkey_enabled)
 		terminfo_set_appkey_mode(term, TRUE);
@@ -562,7 +562,7 @@ void terminfo_stop(TERM_REC *term)
 
 	/* stop cup-mode */
 	if (term->TI_rmcup)
-		tput(tparm(term->TI_rmcup));
+		tput(tiparm(term->TI_rmcup));
 
 	if (term->appkey_enabled)
 		terminfo_set_appkey_mode(term, FALSE);
