$NetBSD: patch-include_tcurses.h,v 1.2 2021/09/01 16:43:59 micha Exp $

Backported upstream patch for ncurses (without w) and pdcurses.

--- include/tcurses.h.orig	2021-07-13 05:56:52.000000000 +0000
+++ include/tcurses.h
@@ -44,7 +44,10 @@
 
 #	if defined(USE_CURSES) || defined(NEED_CURSES_H)
 #		ifdef HAVE_XCURSES
+#			undef bool
+#			define bool XCursesBool
 #			include <xcurses.h>
+#			undef bool
 #			define getattrs(w) (w)->_attrs
 #		else
 #			if defined(HAVE_NCURSESW_NCURSES_H)
@@ -75,7 +78,7 @@
 #					endif /* HAVE_NCURSES_NCURSES_H */
 #				endif /* HAVE_NCURSES_H */
 #			endif /* HAVE_NCURSESW_NCURSES_H */
-#			if defined(NCURSES_WIDECHAR)
+#			if defined(NCURSES_WIDECHAR) && defined(HAVE_GET_WCH)
 #				define HAVE_NCURSESW 1
 #			endif
 #		endif /* HAVE_NCURSES_H */
