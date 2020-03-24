$NetBSD: patch-display.h,v 1.2 2020/03/24 07:00:22 rillig Exp $

display.c: In function 'disp_readev_fn':
display.c:3590:39: error: array subscript has type 'char' [-Werror=char-subscripts]
                   D_mouse_parse.params[D_mouse_parse.state] = 0;
                                       ^
display.c:3605:43: error: array subscript has type 'char' [-Werror=char-subscripts]
                       D_mouse_parse.params[D_mouse_parse.state] *= 10;
                                           ^
display.c:3606:43: error: array subscript has type 'char' [-Werror=char-subscripts]
                       D_mouse_parse.params[D_mouse_parse.state] += c - '0';
                                           ^
display.c:3618:43: error: array subscript has type 'char' [-Werror=char-subscripts]
                       D_mouse_parse.params[D_mouse_parse.state] = 0;
                                           ^
display.c:3626:39: error: array subscript has type 'char' [-Werror=char-subscripts]
                   D_mouse_parse.params[D_mouse_parse.state++] = c;
                                       ^

The constants for the state are from an anonymous enum at the top of
display.c. They are all small nonnegative numbers.

https://savannah.gnu.org/bugs/index.php?58034

--- display.h.orig	2020-02-05 20:09:38.000000000 +0000
+++ display.h
@@ -61,7 +61,7 @@ struct win;			/* forward declaration */
 struct mouse_parse
 {
   char sgrmode;                 /* non-zero if parsing an SGR sequence */
-  char state;                   /* current state of parsing */
+  int state;                    /* current state of parsing */
   int params[3];                /* parsed params: button, x, y */
 };
 
