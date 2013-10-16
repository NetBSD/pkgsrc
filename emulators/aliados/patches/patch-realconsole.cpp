$NetBSD: patch-realconsole.cpp,v 1.1 2013/10/16 23:59:36 roy Exp $

--- realconsole.cpp.orig	2005-05-14 21:11:38.000000000 +0000
+++ realconsole.cpp
@@ -5,11 +5,15 @@
 
 #ifndef NO_CURSES
 
-#include <ncurses.h>
 #include <term.h>
 
 #endif
 
+#ifndef ERR
+#define	ERR	(-1)	/* Error return */
+#define	OK	(0)	/* Success return */
+#endif
+
 #include <termios.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -223,7 +227,7 @@ inline void calltparm (const char * str,
 {
 	if (str != NULL)
 	{
-		calltputs (tparm ( (char *) str, n) );
+		calltputs (tparm ( (char *) str, n, 0, 0, 0, 0, 0, 0, 0, 0) );
 	}
 }
 
