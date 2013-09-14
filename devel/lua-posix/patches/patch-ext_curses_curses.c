$NetBSD: patch-ext_curses_curses.c,v 1.1 2013/09/14 09:06:48 ryoon Exp $

--- ext/curses/curses.c.orig	2013-09-09 07:15:14.000000000 +0000
+++ ext/curses/curses.c
@@ -76,6 +76,10 @@ static const char *RIPOFF_TABLE        =
 
 #define B(v) ((((int) (v)) == OK))
 
+#ifndef true
+#define true 1
+#endif
+
 /* ======================================================= */
 
 #define LC_NUMBER(v)                        \
@@ -452,7 +456,10 @@ static void register_curses_constants(lu
     CC(KEY_MOVE)        CC(KEY_NEXT)        CC(KEY_OPEN)
     CC(KEY_OPTIONS)     CC(KEY_PREVIOUS)    CC(KEY_REDO)
     CC(KEY_REFERENCE)   CC(KEY_REFRESH)     CC(KEY_REPLACE)
-    CC(KEY_RESIZE)      CC(KEY_RESTART)     CC(KEY_RESUME)
+#if defined(HAVE_DECL_KEY_RESIZE)
+    CC(KEY_RESIZE)
+#endif
+    CC(KEY_RESTART)     CC(KEY_RESUME)
     CC(KEY_SAVE)        CC(KEY_SBEG)        CC(KEY_SCANCEL)
     CC(KEY_SCOMMAND)    CC(KEY_SCOPY)       CC(KEY_SCREATE)
     CC(KEY_SDC)         CC(KEY_SDL)         CC(KEY_SELECT)
