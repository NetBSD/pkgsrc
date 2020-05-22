$NetBSD: patch-programs_wineconsole_curses.c,v 1.1 2020/05/22 17:44:42 nia Exp $

_acs_map in NetBSD curses is the equivalent of acs_map in ncurses.

--- programs/wineconsole/curses.c.orig	2019-03-15 20:18:31.000000000 +0000
+++ programs/wineconsole/curses.c
@@ -125,7 +125,7 @@ MAKE_FUNCPTR(getmouse)
 MAKE_FUNCPTR(mouseinterval)
 MAKE_FUNCPTR(mousemask)
 #endif
-MAKE_FUNCPTR(acs_map)
+MAKE_FUNCPTR(_acs_map)
 
 #undef MAKE_FUNCPTR
 
@@ -189,7 +189,7 @@ static BOOL WCCURSES_bind_libcurses(void
     LOAD_FUNCPTR(mouseinterval)
     LOAD_FUNCPTR(mousemask)
 #endif
-    LOAD_FUNCPTR(acs_map)
+    LOAD_FUNCPTR(_acs_map)
 
 #undef LOAD_FUNCPTR
 
