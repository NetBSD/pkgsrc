$NetBSD: patch-include_tcurses.h,v 1.1 2021/08/27 17:45:26 micha Exp $

Backported upstream patch for ncurses (without w).

--- include/tcurses.h.orig	2021-07-13 05:56:52.000000000 +0000
+++ include/tcurses.h
@@ -75,7 +75,7 @@
 #					endif /* HAVE_NCURSES_NCURSES_H */
 #				endif /* HAVE_NCURSES_H */
 #			endif /* HAVE_NCURSESW_NCURSES_H */
-#			if defined(NCURSES_WIDECHAR)
+#			if defined(NCURSES_WIDECHAR) && defined(HAVE_GET_WCH)
 #				define HAVE_NCURSESW 1
 #			endif
 #		endif /* HAVE_NCURSES_H */
