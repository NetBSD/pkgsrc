$NetBSD: patch-fblib.c,v 1.1 2025/10/13 13:04:19 ryoon Exp $

To fix GCC 14 build:
* Use modern standard.
* Add missing include.
* Add missing return types.

--- fblib.c.orig	1995-11-17 18:19:11.000000000 +0000
+++ fblib.c
@@ -2,6 +2,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h> /* For malloc(3) */
 #ifndef __MSDOS__
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
@@ -100,8 +101,7 @@ XColor *fb_xcoltbl = NULL; /* [fb_xcoln]
 char *fb_xcolf = NULL; /* [fb_xcoln] */
 
 #if USE_TITLE
-int GetFontmetric(fontname, str)
-     char *fontname; char *str;
+int GetFontmetric(char *fontname, char *str)
 {
   Font fnt;
   int fontdirec, fontasc, fontdsc;
@@ -147,8 +147,7 @@ int SetupWindow()
  * wx, wy, wxs, wys - default window geometry
  * fb_xsize, fb_ysize - image size
  */
-int OpenWindow(argc, argv, wname)
-     int argc; char **argv; char *wname;
+int OpenWindow(int argc, char **argv, char *wname)
 {
   unsigned long mask;
   XSetWindowAttributes at;
@@ -271,40 +270,34 @@ int (*press_hook)() = dummy;
 int (*keybd_hook)() = dummy;
 
 /* regist main event loop */
-void FB_setevent(p)
-     int (*p)();
+void FB_setevent(int (*p)())
 {
   event_hook = p;
 }
 
 /* regist key event */
-void FB_setkeyevent(p)
-     int (*p)();
+void FB_setkeyevent(int (*p)())
 {
   keybd_hook = p;
 }
 
 /* regist mouse event */
-void FB_setmouseevent(p)
-     int (*p)();
+void FB_setmouseevent(int (*p)())
 {
   press_hook = p;
 }
 
-void FB_setredrawevent(p)
-     int (*p)();
+void FB_setredrawevent(int (*p)())
 {
   redraw_hook = p;
 }
 
-void FB_setredraw2event(p)
-     int (*p)();
+void FB_setredraw2event(int (*p)())
 {
   redraw_hook2 = p;
 }
 
-void FB_setresizeevent(p)
-     int (*p)();
+void FB_setresizeevent(int (*p)())
 {
   resize_hook = p;
 }
@@ -331,8 +324,7 @@ void RedrawTitle()
  * xs, ys - redraw size
  * imgx, imgy - img pos offset
  */
-int FB_redrawimage(x0, y0, xs, ys)
-     int x0, y0, xs, ys;
+int FB_redrawimage(int x0, int y0, int xs, int ys)
 {
   int x, y, w, h, f;
 
@@ -379,8 +371,7 @@ int FB_redrawimage(x0, y0, xs, ys)
   return (*redraw_hook2)(x0, y0, xs, ys) < 0;
 }
 
-void ResizeWindow(x,y,w,h)
-     int x, y, w, h;
+void ResizeWindow(int x, int y, int w, int h)
 {
   if ((*resize_hook)(x, y, w, h))
     return;
@@ -394,8 +385,7 @@ void ResizeWindow(x,y,w,h)
   FB_redrawimage(0, 0, wxs, wys);
 }
 
-int mouse_button(f, x, y)
-     int f, x, y;
+int mouse_button(int f, int x, int y)
 {
   int i, r;
   
@@ -420,8 +410,7 @@ int mouse_button(f, x, y)
   return r;
 }
 
-int keyboard(e)
-     XKeyEvent *e;
+int keyboard(XKeyEvent *e)
 {
   int n, i, r;
   char keybuf[10];
@@ -476,7 +465,7 @@ void FB_event()
       break;
 #endif
     case KeyPress:
-      fin = keyboard(&e);
+      fin = keyboard(&(e.xkey));
       break;
     default:
       break;
@@ -487,8 +476,7 @@ void FB_event()
 /********************************************************************/
 
 
-int FB_libinit(fbname)
-     char *fbname;
+int FB_libinit(char *fbname)
 {
   int i;
 
@@ -508,8 +496,7 @@ void FB_libend()
   FreeWindow();
 }
 
-int FB_open(argc, argv, wname)
-     int argc; char **argv; char *wname;
+int FB_open(int argc, char **argv, char *wname)
 {
   fb_xcoltbl = (XColor *)malloc(sizeof(*fb_xcoltbl)*fb_xcoln);
   fb_xcolf = (char *)malloc(sizeof(*fb_xcolf)*fb_xcoln);
@@ -532,8 +519,7 @@ int FB_close()
   return 0;
 }
 
-void FB_disp(mode)
-     int mode;
+void FB_disp(int mode)
 {
   if (mode & 2) {
     XMapWindow(dsp, win);
@@ -543,8 +529,7 @@ void FB_disp(mode)
 }
 
 
-void FB_putline2(x, y, xs, p)
-     int x; int y; int xs; unsigned long *p;
+void FB_putline2(int x, int y, int xs, unsigned long *p)
 {
   int xx,xxs;
   
@@ -578,8 +563,7 @@ static int freecolidx()
   return 0;
 }
 
-int FB_alloccol(px, p)
-     FBPIX *px; PIXEL *p;
+int FB_alloccol(FBPIX *px, PIXEL *p)
 {
 #define PIXRGB(n) ((n<<8)|n)
   FBPIX i;
@@ -597,14 +581,12 @@ int FB_alloccol(px, p)
 #undef PIXRGB
 }
 
-void FB_freecol(px)
-     FBPIX px;
+void FB_freecol(FBPIX px)
 {
   *(fb_xcolf+px) = 0;
 }
 
-void FB_putline3(x, y, xs, p)
-     int x; int y; int xs; FBPIX *p;
+void FB_putline3(int x, int y, int xs, FBPIX *p)
 {
   int xx, xxs;
   
@@ -620,8 +602,7 @@ void FB_putline3(x, y, xs, p)
 }
 
 /* mouse cursor font control */
-void FB_setmousecursor(f)
-     int f;
+void FB_setmousecursor(int f)
 {
   if (f == fb_mcn)
     return;
