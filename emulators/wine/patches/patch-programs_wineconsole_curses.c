$NetBSD: patch-programs_wineconsole_curses.c,v 1.2 2020/05/23 21:20:39 adam Exp $

_acs_map in NetBSD curses is the equivalent of acs_map in ncurses.

--- programs/wineconsole/curses.c.orig	2019-11-25 15:10:40.000000000 +0000
+++ programs/wineconsole/curses.c
@@ -125,7 +125,11 @@ MAKE_FUNCPTR(getmouse)
 MAKE_FUNCPTR(mouseinterval)
 MAKE_FUNCPTR(mousemask)
 #endif
+#ifdef __NetBSD__
+MAKE_FUNCPTR(_acs_map)
+#else
 MAKE_FUNCPTR(acs_map)
+#endif
 
 #undef MAKE_FUNCPTR
 
@@ -189,7 +193,11 @@ static BOOL WCCURSES_bind_libcurses(void
     LOAD_FUNCPTR(mouseinterval)
     LOAD_FUNCPTR(mousemask)
 #endif
+#ifdef __NetBSD__
+    LOAD_FUNCPTR(_acs_map)
+#else
     LOAD_FUNCPTR(acs_map)
+#endif
 
 #undef LOAD_FUNCPTR
 
