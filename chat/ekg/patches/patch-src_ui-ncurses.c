$NetBSD: patch-src_ui-ncurses.c,v 1.1 2020/01/20 17:32:49 adam Exp $

Fix curses.

--- src/ui-ncurses.c.orig	2020-01-20 16:47:44.000000000 +0000
+++ src/ui-ncurses.c
@@ -351,7 +351,7 @@ int contacts_size()
 	if (!config_contacts)
 		return 0;
 
-	if (config_contacts_size + 2 > (stdscr->_maxx + 1) / 2)
+	if (config_contacts_size + 2 > (getmaxx(stdscr) + 1) / 2)
 		return 0;
 
 	return config_contacts_size + (contacts_frame) ? 1 : 0;
@@ -618,9 +618,9 @@ void window_resize()
 	list_t l;
 
 	left = 0;
-	right = stdscr->_maxx + 1;
+	right = getmaxx(stdscr) + 1;
 	top = config_header_size;
-	bottom = stdscr->_maxy + 1 - input_size - config_statusbar_size;
+	bottom = getmaxy(stdscr) + 1 - input_size - config_statusbar_size;
 	width = right - left;
 	height = bottom - top;
 
@@ -737,13 +737,13 @@ void window_resize()
 
 		if (w->left < 0)
 			w->left = 0;
-		if (w->left > stdscr->_maxx)
-			w->left = stdscr->_maxx;
+		if (w->left > getmaxx(stdscr))
+			w->left = getmaxx(stdscr);
 
 		if (w->top < 0)
 			w->top = 0;
-		if (w->top > stdscr->_maxy)
-			w->top = stdscr->_maxy;
+		if (w->top > getmaxy(stdscr))
+			w->top = getmaxy(stdscr);
 
 		mvwin(w->window, w->top, w->left);
 
@@ -756,8 +756,8 @@ void window_resize()
 	}
 
 	if (window_current) {
-		mouse_area_resize("window_current", window_current->window->_maxy, window_current->window->_maxx);
-		mouse_area_move("window_current", window_current->window->_begy, window_current->window->_begx);
+		mouse_area_resize("window_current", getmaxy(window_current->window), getmaxx(window_current->window));
+		mouse_area_move("window_current", getbegy(window_current->window), getbegx(window_current->window));
 	}
 
 	ui_screen_width = width;
@@ -1055,11 +1055,11 @@ static void window_refresh()
 		wnoutrefresh(w->window);
 	}
 	
-	mvwin(status, stdscr->_maxy + 1 - input_size - config_statusbar_size, 0);
-	mouse_area_move("status", stdscr->_maxy + 1 - input_size - config_statusbar_size, 0);
+	mvwin(status, getmaxy(stdscr) + 1 - input_size - config_statusbar_size, 0);
+	mouse_area_move("status", getmaxy(stdscr) + 1 - input_size - config_statusbar_size, 0);
 
-	wresize(input, input_size, input->_maxx + 1);
-	mvwin(input, stdscr->_maxy - input_size + 1, 0);
+	wresize(input, input_size, getmaxx(input) + 1);
+	mvwin(input, getmaxy(stdscr) - input_size + 1, 0);
 }
 
 /*
@@ -1234,14 +1234,14 @@ static struct window *window_new(const c
 
 			array_free(argv);
 
-			if (w.left > stdscr->_maxx)
-				w.left = stdscr->_maxx;
-			if (w.top > stdscr->_maxy)
-				w.top = stdscr->_maxy;
-			if (w.left + w.width > stdscr->_maxx)
-				w.width = stdscr->_maxx + 1 - w.left;
-			if (w.top + w.height > stdscr->_maxy)
-				w.height = stdscr->_maxy + 1 - w.top;
+			if (w.left > getmaxx(stdscr))
+				w.left = getmaxx(stdscr);
+			if (w.top > getmaxy(stdscr))
+				w.top = getmaxy(stdscr);
+			if (w.left + w.width > getmaxx(stdscr))
+				w.width = getmaxx(stdscr) + 1 - w.left;
+			if (w.top + w.height > getmaxy(stdscr))
+				w.height = getmaxy(stdscr) + 1 - w.top;
 		}
 		
 		if (!w.target) {
@@ -1787,7 +1787,7 @@ static void update_header(int commit)
 		
 		wmove(header, y, 0);
 
-		for (x = 0; x <= status->_maxx; x++)
+		for (x = 0; x <= getmaxx(status); x++)
 			waddch(header, ' ');
 	}
 
@@ -1836,13 +1836,13 @@ int window_printat(WINDOW *w, int x, int
 
 		wmove(w, y, 0);
 
-		for (i = 0; i <= w->_maxx; i++)
+		for (i = 0; i <= getmaxx(w); i++)
 			waddch(w, ' ');
 	}
 
 	wmove(w, y, x);
 			
-	while (*p && *p != '}' && x <= w->_maxx) {
+	while (*p && *p != '}' && x <= getmaxx(w)) {
 		int i, nest;
 
 		if (*p != '%') {
@@ -1886,7 +1886,7 @@ int window_printat(WINDOW *w, int x, int
 					bold = 0;
 					break;
 				case '|':
-					while (x <= w->_maxx) {
+					while (x <= getmaxx(w)) {
 						waddch(w, ' ');
 						x++;
 					}
@@ -2081,7 +2081,7 @@ static int mouse_statusbar_update (int x
 		}
 	}
 
-	while (p && *p && *p != '}' && x <= status->_maxx) {
+	while (p && *p && *p != '}' && x <= getmaxx(status)) {
 		int i, nest;
 
 		if (*p != '%') {
@@ -2097,7 +2097,7 @@ static int mouse_statusbar_update (int x
 		if (*p != '{') {
 			switch (*p) {
 				case '|':
-					while (x <= status->_maxx)
+					while (x <= getmaxx(status))
 						x++;
 					break;
 				case '}':
@@ -3078,8 +3078,8 @@ void ui_ncurses_init()
 		use_default_colors();
 	}
 
-	ui_screen_width = stdscr->_maxx + 1;
-	ui_screen_height = stdscr->_maxy + 1;
+	ui_screen_width = getmaxx(stdscr) + 1;
+	ui_screen_height = getmaxy(stdscr) + 1;
 	ui_need_refresh = 0;
 
 #ifndef GG_DEBUG_DISABLE
@@ -3087,16 +3087,16 @@ void ui_ncurses_init()
 #endif
 	window_current = window_new(NULL, 0);
 
-	status = newwin(1, stdscr->_maxx + 1, stdscr->_maxy - 1, 0);
-	input = newwin(1, stdscr->_maxx + 1, stdscr->_maxy, 0);
+	status = newwin(1, getmaxx(stdscr) + 1, getmaxy(stdscr) - 1, 0);
+	input = newwin(1, getmaxx(stdscr) + 1, getmaxy(stdscr), 0);
 	keypad(input, TRUE);
 	nodelay(input, TRUE);
 	mouse_event("disable");
 
 	area.name = "status";
 	area.size.y = 1;
-	area.size.x = stdscr->_maxx + 1;
-	area.start.y = stdscr->_maxy - 1;
+	area.size.x = getmaxx(stdscr) + 1;
+	area.start.y = getmaxy(stdscr) - 1;
 	area.start.x = 0;
 	area.bevents = NULL;
 
@@ -3106,10 +3106,10 @@ void ui_ncurses_init()
 	mouse_area_add(&area);
 
 	area.name = "window_current";
-	area.size.y = window_current->window->_maxy;
-	area.size.x = window_current->window->_maxx;
-	area.start.y = window_current->window->_begy;
-	area.start.x = window_current->window->_begx;
+	area.size.y = getmaxy(window_current->window);
+	area.size.x = getmaxx(window_current->window);
+	area.start.y = getbegy(window_current->window);
+	area.start.x = getbegx(window_current->window);
 	area.bevents = NULL;
 
 	mouse_bevent_add(&area, BUTTON1_PRESSED, mouse_bevent_current);
@@ -3322,10 +3322,10 @@ static void line_adjust()
 	int prompt_len = (lines) ? 0 : window_current->prompt_len;
 
 	line_index = strlen(line);
-	if (strlen(line) < input->_maxx - 9 - prompt_len)
+	if (strlen(line) < getmaxx(input) - 9 - prompt_len)
 		line_start = 0;
 	else
-		line_start = strlen(line) - strlen(line) % (input->_maxx - 9 - prompt_len);
+		line_start = strlen(line) - strlen(line) % (getmaxx(input) - 9 - prompt_len);
 }
 
 /*
@@ -4846,10 +4846,10 @@ static void ui_ncurses_loop()
 
 redraw_prompt:
 
-		if (line_index - line_start > input->_maxx - 9 - window_current->prompt_len)
-			line_start += input->_maxx - 19 - window_current->prompt_len;
+		if (line_index - line_start > getmaxx(input) - 9 - window_current->prompt_len)
+			line_start += getmaxx(input) - 19 - window_current->prompt_len;
 		if (line_index - line_start < 10) {
-			line_start -= input->_maxx - 19 - window_current->prompt_len;
+			line_start -= getmaxx(input) - 19 - window_current->prompt_len;
 			if (line_start < 0)
 				line_start = 0;
 		}
@@ -4876,7 +4876,7 @@ redraw_prompt:
 				if (config_aspell == 1)
 					spellcheck(p, aspell_line);
 
-                                for (j = 0; j + line_start < strlen(p) && j < input->_maxx + 1; j++) {
+                                for (j = 0; j + line_start < strlen(p) && j < getmaxx(input) + 1; j++) {
                                     
 				    if (aspell_line[line_start + j] == ASPELLBADCHAR) /* jesli b³êdny to wy¶wietlamy podkre¶lony */
                                         print_char_underlined(input, i, j, p[line_start + j]);
@@ -4884,7 +4884,7 @@ redraw_prompt:
 				        print_char(input, i, j, p[j + line_start]);
 				}
 #else
-                                for (j = 0; j + line_start < strlen((char*) p) && j < input->_maxx + 1; j++)
+                                for (j = 0; j + line_start < strlen((char*) p) && j < getmaxx(input) + 1; j++)
                                         print_char(input, i, j, p[j + line_start]);
 #endif
 			}
@@ -4902,7 +4902,7 @@ redraw_prompt:
 			if (config_aspell == 1)
 		    		spellcheck(line, aspell_line);
 
-                        for (i = 0; i < input->_maxx + 1 - window_current->prompt_len && i < strlen(line) - line_start; i++) {
+                        for (i = 0; i < getmaxx(input) + 1 - window_current->prompt_len && i < strlen(line) - line_start; i++) {
 
 				if (aspell_line[line_start + i] == ASPELLBADCHAR) /* jesli b³êdny to wy¶wietlamy podkre¶lony */
                                     print_char_underlined(input, 0, i + window_current->prompt_len, line[line_start + i]);
@@ -4910,15 +4910,15 @@ redraw_prompt:
                                     print_char(input, 0, i + window_current->prompt_len, line[line_start + i]);
 			}
 #else
-                        for (i = 0; i < input->_maxx + 1 - window_current->prompt_len && i < strlen(line) - line_start; i++)
+                        for (i = 0; i < getmaxx(input) + 1 - window_current->prompt_len && i < strlen(line) - line_start; i++)
                                 print_char(input, 0, i + window_current->prompt_len, line[line_start + i]);
 #endif
 
 			wattrset(input, color_pair(COLOR_BLACK, 1, COLOR_BLACK));
 			if (line_start > 0)
 				mvwaddch(input, 0, window_current->prompt_len, '<');
-			if (strlen(line) - line_start > input->_maxx + 1 - window_current->prompt_len)
-				mvwaddch(input, 0, input->_maxx, '>');
+			if (strlen(line) - line_start > getmaxx(input) + 1 - window_current->prompt_len)
+				mvwaddch(input, 0, getmaxx(input), '>');
 			wattrset(input, color_pair(COLOR_WHITE, 0, COLOR_BLACK));
 			wmove(input, 0, line_index - line_start + window_current->prompt_len);
 		}
@@ -5856,11 +5856,11 @@ static int ui_ncurses_event(const char *
 
 				array_free(argv);
 					
-				if (w->left + w->width > stdscr->_maxx + 1)
-					w->left = stdscr->_maxx + 1 - w->width;
+				if (w->left + w->width > getmaxx(stdscr) + 1)
+					w->left = getmaxx(stdscr) + 1 - w->width;
 				
-				if (w->top + w->height > stdscr->_maxy + 1)
-					w->top = stdscr->_maxy + 1 - w->height;
+				if (w->top + w->height > getmaxy(stdscr) + 1)
+					w->top = getmaxy(stdscr) + 1 - w->height;
 				
 				if (w->floating)
 					mvwin(w->window, w->top, w->left);
@@ -6111,12 +6111,12 @@ void header_statusbar_resize(const char 
 		if (!header) {
 			struct mouse_area_t a;
 
-			header = newwin(config_header_size, stdscr->_maxx + 1, 0, 0);
+			header = newwin(config_header_size, getmaxx(stdscr) + 1, 0, 0);
 
 			a.name = "header";
 			a.start.x = 0;
 			a.start.y = 0;
-			a.size.x = stdscr->_maxx + 1;
+			a.size.x = getmaxx(stdscr) + 1;
 			a.size.y = config_header_size;
 			a.bevents = NULL;
 
@@ -6124,8 +6124,8 @@ void header_statusbar_resize(const char 
 			mouse_bevent_add(&a, BUTTON1_DOUBLE_CLICKED, mouse_bevent_header);
 			mouse_area_add(&a);
 		} else {
-			wresize(header, config_header_size, stdscr->_maxx + 1);
-			mouse_area_resize("header", config_header_size, stdscr->_maxx + 1);
+			wresize(header, config_header_size, getmaxx(stdscr) + 1);
+			mouse_area_resize("header", config_header_size, getmaxx(stdscr) + 1);
 		}
 
 		update_header(0);
@@ -6139,10 +6139,10 @@ void header_statusbar_resize(const char 
 
 	window_resize();
 
-	wresize(status, config_statusbar_size, stdscr->_maxx + 1);
-	mvwin(status, stdscr->_maxy + 1 - input_size - config_statusbar_size, 0);
-	mouse_area_resize("status", config_statusbar_size, stdscr->_maxx + 1);
-	mouse_area_move("status", stdscr->_maxy + 1 - input_size - config_statusbar_size, 0);
+	wresize(status, config_statusbar_size, getmaxx(stdscr) + 1);
+	mvwin(status, getmaxy(stdscr) + 1 - input_size - config_statusbar_size, 0);
+	mouse_area_resize("status", config_statusbar_size, getmaxx(stdscr) + 1);
+	mouse_area_move("status", getmaxy(stdscr) + 1 - input_size - config_statusbar_size, 0);
 
 	update_statusbar(0);
 
