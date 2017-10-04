$NetBSD: patch-fig2dev_fig2dev.c,v 1.2 2017/10/04 12:01:43 wiz Exp $

NetBSD defines _setmode, but is not Windows.
https://sourceforge.net/p/mcj/tickets/17/

--- fig2dev/fig2dev.c.orig	2017-01-04 11:04:09.000000000 +0000
+++ fig2dev/fig2dev.c
@@ -37,6 +37,9 @@
 #include <string.h>
 #include "bool.h"
 #include <locale.h>
+#ifdef __NetBSD__
+#undef HAVE__SETMODE
+#endif
 /* setmode() exists on DOS/Windows. It sets file mode to text or binary.
  * setmode() is declared in <io.h>, O_BINARY is declared in <fcntl.h>. */
 #ifdef HAVE__SETMODE
