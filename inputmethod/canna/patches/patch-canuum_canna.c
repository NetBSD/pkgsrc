$NetBSD: patch-canuum_canna.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

- Appease prototype warnings.
- Remove unnecessary ops.

--- canuum/canna.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ canuum/canna.c
@@ -52,4 +52,16 @@ static char rcsid[] = "$Id: canna.c,v 1.
 #endif
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#if STDC_HEADERS
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
+#endif /* STDC_HEADERS */
+
 #include "commonhd.h"
 #include "sdefine.h"
@@ -95,6 +107,4 @@ static char rcsid[] = "$Id: canna.c,v 1.
 #define NOREDRAW      0
 
-extern	int	errno;
-
 static int maxmodelen;
 static int maxwidth = 0;
@@ -1239,8 +1249,6 @@ int flag;
 
 #ifdef TERMINFO
-  int fd, res;
 
-  fd = open("/dev/null", O_WRONLY, &res);
-  setupterm(term, fd, (int *)0);
+  setupterm(term, 0, NULL);
 
   cannakeyentry(key_f1,    CANNA_KEY_F1);
@@ -1271,5 +1279,4 @@ int flag;
 #endif
 
-  resetterm();
 #endif
 
