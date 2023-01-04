$NetBSD: patch-bsdinstall.c,v 1.1 2023/01/04 18:35:56 vins Exp $

Portability fixes for non-BSD systems.

--- bsdinstall.c.orig	2023-01-04 18:13:49.292371298 +0000
+++ bsdinstall.c
@@ -73,9 +73,9 @@ __RCSID("NetBSD: xinstall.c,v 1.114 2009
 #include <fcntl.h>
 #include <libgen.h>
 #include <stdio.h>
-#include <string.h>
-#include <unistd.h>
 #if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/string.h>
+#include <nbcompat/unistd.h>
 #include <nbcompat/grp.h>
 #include <nbcompat/paths.h>
 #include <nbcompat/pwd.h>
@@ -83,6 +83,8 @@ __RCSID("NetBSD: xinstall.c,v 1.114 2009
 #include <nbcompat/util.h>
 #include <nbcompat/vis.h>
 #else
+#include <string.h>
+#include <unistd.h>
 #include <grp.h>
 #include <paths.h>
 #include <pwd.h>
@@ -110,6 +112,10 @@ __RCSID("NetBSD: xinstall.c,v 1.114 2009
 #define STRIP_ARGS_MAX 32
 #define BACKUP_SUFFIX ".old"
 
+#ifndef MAXBSIZE
+#define MAXBSIZE (64 * 1024)
+#endif
+
 extern void *setmode(const char *p);
 
 static int	dobackup, dodir, dostrip, dolink, dopreserve, dorename, dounpriv;
