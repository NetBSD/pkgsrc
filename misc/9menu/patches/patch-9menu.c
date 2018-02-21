$NetBSD: patch-9menu.c,v 1.1 2018/02/21 15:12:00 triaxx Exp $

Bug fix for use with keyboard. More prototypes.
https://github.com/arnoldrobbins/9menu/commit/43465036b6f986dd2638504e9ce51b3b6dc976e3

Fix resource leak: fp.
Fix compilation warngings.
From Debian

--- 9menu.c.orig	2015-06-25 20:15:02.000000000 +0000
+++ 9menu.c
@@ -113,7 +113,7 @@ char *fontlist[] = {	/* default font lis
 /* the 9menu icon, for garish window managers */
 #define nine_menu_width 40
 #define nine_menu_height 40
-static unsigned char nine_menu_bits[] = {
+static char nine_menu_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x04, 0x00,
    0x80, 0x00, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x00,
    0x00, 0xfc, 0xff, 0xff, 0x00, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x04,
@@ -154,11 +154,14 @@ int numitems;
 
 char *shell = "/bin/sh";	/* default shell */
 
-extern void usage(), run_menu(), spawn(), ask_wm_for_delete();
-extern void reap(), set_wm_hints();
-extern void redraw(), teleportmenu(), warpmouse(), restoremouse();
-extern void memory();
-extern int args();
+extern void usage(), run_menu(), spawn(char *com), ask_wm_for_delete();
+extern void reap(int sig), set_wm_hints(int wide, int high);
+extern void redraw(int cur, int high, int wide);
+extern void teleportmenu(int cur, int wide, int high);
+extern void warpmouse(int cur, int wide, int high);
+extern void restoremouse();
+extern void memory(char *msg);
+extern int args(int argc, char **argv);
 
 /* memory --- print the out of memory message and die */
 
@@ -278,11 +281,13 @@ main(int argc, char **argv)
 		} else {
 			fp = fopen(filename, "r");
 		}
+
 		if (fp == NULL) {
 			fprintf(stderr, "%s: couldn't open '%s'\n", progname,
 				filename);
 			exit(1);
 		}
+
 		while (fgets(fbuf, sizeof fbuf, fp)) {
 			char *s = fbuf;
 			strtok(s, "\n");
@@ -327,6 +332,7 @@ main(int argc, char **argv)
 			strcpy(f_argv[nlabels], s);
 			++nlabels;
 		}
+    fclose(fp);
 	}
 
 	labels = (char **) malloc((numitems + nlabels) * sizeof(char *));
@@ -368,8 +374,10 @@ main(int argc, char **argv)
 		fprintf(stderr, "\n");
 		exit(1);
 	}
+
 	screen = DefaultScreen(dpy);
 	root = RootWindow(dpy, screen);
+
 	/*
 	 * This used to be
 	 * black = BlackPixel(dpy, screen);
@@ -471,10 +479,10 @@ spawn(char *com)
 /* reap --- collect dead children */
 
 void
-reap(int s)
+reap(int sig)
 {
 	(void) wait((int *) NULL);
-	signal(s, reap);
+	signal(sig, reap);
 }
 
 /* usage --- print a usage message and die */
@@ -585,12 +593,15 @@ run_menu()
 			    && key != CONFIG_MENU_SELECT_KEY)
 				break;
 
+			/* adjust i so mapping will work */
 			if (key == CONFIG_MENU_UP_KEY) {
 				old = cur;
 				cur--;
+				i--;
 			} else if (key == CONFIG_MENU_DOWN_KEY) {
 				old = cur;
 				cur++;
+				i++;
 			}
 			
 			while (cur < 0)
@@ -787,7 +798,7 @@ teleportmenu(int cur, int wide, int high
 	Window wdummy;
 
 	if (XQueryPointer(dpy, menuwin, &wdummy, &wdummy, &x, &y,
-			       &dummy, &dummy, &dummy))
+			       &dummy, &dummy, (unsigned int *)&dummy))
 		XMoveWindow(dpy, menuwin, x-wide/2, y-cur*high-high/2);
 }
 
@@ -805,7 +816,7 @@ warpmouse(int cur, int wide, int high)
 	offset += 6;	/* fudge factor */
 
 	if (XQueryPointer(dpy, menuwin, &wdummy, &wdummy, &savex, &savey,
-			       &dummy, &dummy, &dummy))
+			       &dummy, &dummy, (unsigned int *)&dummy))
 		XWarpPointer(dpy, None, menuwin, 0, 0, 0, 0,
 				wide/2, cur*high-high/2+offset);
 }
