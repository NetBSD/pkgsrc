$NetBSD: patch-tmux.c,v 1.2 2025/10/05 11:04:21 leot Exp $

Add support for QNX.

--- tmux.c.orig	2024-10-05 05:57:07.000000000 +0000
+++ tmux.c
@@ -22,7 +22,9 @@
 
 #include <errno.h>
 #include <fcntl.h>
-#include <langinfo.h>
+#ifndef __QNX__
+# include <langinfo.h>
+#endif
 #include <locale.h>
 #include <pwd.h>
 #include <signal.h>
@@ -361,9 +363,11 @@ main(int argc, char **argv)
 	    setlocale(LC_CTYPE, "C.UTF-8") == NULL) {
 		if (setlocale(LC_CTYPE, "") == NULL)
 			errx(1, "invalid LC_ALL, LC_CTYPE or LANG");
+#ifndef __QNX__
 		s = nl_langinfo(CODESET);
 		if (strcasecmp(s, "UTF-8") != 0 && strcasecmp(s, "UTF8") != 0)
 			errx(1, "need UTF-8 locale (LC_CTYPE) but have %s", s);
+#endif
 	}
 
 	setlocale(LC_TIME, "");
