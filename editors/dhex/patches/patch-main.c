$NetBSD: patch-main.c,v 1.1 2020/03/23 19:45:37 nia Exp $

Required by NetBSD curses.

--- main.c.orig	2019-01-19 16:17:37.000000000 +0000
+++ main.c
@@ -530,6 +530,7 @@ int main(int argc,char** argv)
 		output->win=initscr();
 		pairsinit(output);
 		noecho();
+		raw();
 		nodelay(output->win,1);
 		if (keyboardsetupreq) keyboardsetup(output,configfile);
 		if (bhexcalc)
