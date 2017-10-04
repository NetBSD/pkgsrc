$NetBSD: patch-fig2dev_dev_readjpg.c,v 1.2 2017/10/04 12:01:43 wiz Exp $

NetBSD defines _setmode, but is not Windows.
https://sourceforge.net/p/mcj/tickets/17/

--- fig2dev/dev/readjpg.c.orig	2017-01-07 22:04:22.000000000 +0000
+++ fig2dev/dev/readjpg.c
@@ -39,6 +39,9 @@
 #include "object.h"	/* does #include <X11/xpm.h> */
 #include "psimage.h"
 #include "creationdate.h"
+#ifdef __NetBSD__
+#undef HAVE__SETMODE
+#endif
 #ifdef HAVE__SETMODE	/* see fig2dev.c */
 #include <io.h>
 #include <fcntl.h>
