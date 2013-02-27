$NetBSD: patch-tools_session__notify.c,v 1.1 2013/02/27 17:49:15 jperkin Exp $

Need alloca.h on SunOS.

--- tools/session_notify.c.orig	2010-04-13 19:27:48.000000000 +0000
+++ tools/session_notify.c
@@ -18,6 +18,9 @@
  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <errno.h>
 #include <unistd.h>
