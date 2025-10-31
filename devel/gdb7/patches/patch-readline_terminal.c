$NetBSD: patch-readline_terminal.c,v 1.1 2025/10/31 15:05:37 ryoon Exp $

* FIx GCC 14 build.

--- readline/terminal.c.orig	2025-10-21 10:43:05.558549070 +0000
+++ readline/terminal.c
@@ -51,9 +51,9 @@
 /* System-specific feature definitions and include files. */
 #include "rldefs.h"
 
-#if defined (GWINSZ_IN_SYS_IOCTL) && !defined (TIOCGWINSZ)
+#if !defined (TIOCGWINSZ)
 #  include <sys/ioctl.h>
-#endif /* GWINSZ_IN_SYS_IOCTL && !TIOCGWINSZ */
+#endif /* !TIOCGWINSZ */
 
 #ifdef __MSDOS__
 # include <pc.h>
