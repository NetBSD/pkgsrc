$NetBSD: patch-ifp__routines.c,v 1.1 2015/07/09 12:00:14 jperkin Exp $

Use nbcompat.

--- ifp_routines.c.orig	2005-12-03 16:55:06.000000000 +0000
+++ ifp_routines.c
@@ -8,7 +8,12 @@ static const char rcsid[] = "$Id: ifp_ro
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <errno.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/fts.h>
+#else
 #include <fts.h>
+#endif
 #include <unistd.h>
 
 #include "unicodehack.h"
