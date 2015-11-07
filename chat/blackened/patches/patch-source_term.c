$NetBSD: patch-source_term.c,v 1.1 2015/11/07 21:16:36 dholland Exp $

- Don't use <sgtty.h> on modern BSD.

--- source/term.c~	1999-07-26 06:54:34.000000000 +0000
+++ source/term.c
@@ -101,7 +101,8 @@ static	char	rcsid[] = "@(#)$Id: term.c,v
  * i hope other systems based on this don't change it (netbsd,
  * bsdi, freebsd ..)
  */
-#ifdef BSD4_4
+#if defined(BSD4_4) || defined(__NetBSD__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) || defined(__OpenBSD__) || defined(__Bitrig__)
 # include <termios.h>
 # define termio termios
 # define USE_TERMIO
