$NetBSD: patch-src_output.c,v 1.1 2025/06/02 16:49:08 vins Exp $

wprintw(WINDOW *win, const char *fmt, ...);

--- src/output.c.orig	2021-01-10 14:52:39.000000000 +0000
+++ src/output.c
@@ -151,7 +151,7 @@ int print_header(int option) {
 	        erase();
 		    mvwprintw(stdscr,1,2,"bwm-ng v" VERSION" (probing every %2.3fs), press 'h' for help",(float)delay/1000);
             mvwprintw(stdscr,2,2,"input: %s type: %s",input2str(),output_type2str());
-            wprintw(stdscr,show_all_if2str());
+            wprintw(stdscr,"%s",show_all_if2str());
 	        mvwprintw(stdscr,3,2,"%c         iface                   Rx                   Tx                Total",(char)IDLE_CHARS[option]);
 	        /* go to next char for next run */
 	        option++;
