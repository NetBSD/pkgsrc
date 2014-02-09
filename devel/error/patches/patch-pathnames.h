$NetBSD: patch-pathnames.h,v 1.1 2014/02/09 16:48:42 wiedi Exp $

don't include paths.h on SunOS
--- pathnames.h.orig	2005-05-10 20:48:24.000000000 +0000
+++ pathnames.h
@@ -31,7 +31,12 @@
  *	@(#)pathnames.h	8.1 (Berkeley) 6/6/93
  */
 
-#include <paths.h>
+#if defined(__sun)
+# define _PATH_TTY   "/dev/tty"
+# define _PATH_TMP   "/tmp/"
+#else
+# include <paths.h>
+#endif
 
 #define	IG_FILE1	"llib-lc"
 #define	IG_FILE2	"llib-port"
