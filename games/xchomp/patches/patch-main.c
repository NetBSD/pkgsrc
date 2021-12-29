$NetBSD: patch-main.c,v 1.1 2021/12/29 23:56:01 nia Exp $

Add return types.
Allow FRAME_DELAY to be set from the command line.
from FreeBSD Ports.

--- main.c.orig	1994-03-18 05:12:24.000000000 +0000
+++ main.c
@@ -2,7 +2,7 @@
 #define EXTERN
 #include "xchomp.h"
 
-main(argc, argv)
+int main(argc, argv)
 int argc;
 char *argv[];
 {
@@ -10,6 +10,12 @@ char *argv[];
    int			dummy;
    XCharStruct		chars;
    unsigned long	event_mask;
+   int                  fdelay = 0;
+
+   /* User may set FRAME_DELAY from the command line */
+   if (argc >= 2) {
+      fdelay = atoi(argv[1]);
+   }
 
    /* open the display */
    display 	= XOpenDisplay(NULL);
@@ -64,17 +70,18 @@ char *argv[];
    }
 
    /* go to it */
-   play_game();
+   play_game(fdelay);
 
    /* exit */
    do_exit();
+   return 0;
 }
 
 
 /* 
  * The following function contains the main game loop.
  */
-play_game() {
+void play_game(fdelay) {
    register int    i;
    char            c_buf;
    XComposeStatus  status;
@@ -166,7 +173,7 @@ play_game() {
          if (event.xany.window != window) continue;
          switch (event.type) {
             case KeyPress:
-               XLookupString(&event, &c_buf, 1, &last_key, &status);
+               XLookupString((XKeyEvent *) &event, &c_buf, 1, &last_key, &status);
                if (last_key == XK_space)
                   if (!pause_seq())
                      goto demo;
@@ -325,7 +332,11 @@ play_game() {
       XSync(display, False);
 
 #ifdef FRAME_DELAY
-      usleep(FRAME_DELAY);
+      if (fdelay > 0) {
+         usleep(fdelay);
+      } else {
+         usleep(FRAME_DELAY);
+      }
 #endif
 
    } /* while */
@@ -347,7 +358,7 @@ play_game() {
 }
 
 
-do_exit()
+void do_exit()
 {
    destroy_regions();
    XUnmapWindow(display, window);
