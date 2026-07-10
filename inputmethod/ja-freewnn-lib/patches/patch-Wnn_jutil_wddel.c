$NetBSD: patch-Wnn_jutil_wddel.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old style declaration for standard C function

--- Wnn/jutil/wddel.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/wddel.c
@@ -48,7 +48,6 @@ static char *rcs_id = "$Id: wddel.c,v 1.
 #  if HAVE_MALLOC_H
 #    include <malloc.h>
 #  endif
-extern char *getenv ();
 #endif /* STDC_HEADERS */
 
 #if HAVE_UNISTD_H
