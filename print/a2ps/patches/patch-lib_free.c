$NetBSD: patch-lib_free.c,v 1.1 2023/04/13 18:29:47 wiz Exp $

malloc/free confusion
https://savannah.gnu.org/bugs/index.php?64040

--- lib/free.c.orig	2023-04-12 17:05:08.000000000 +0000
+++ lib/free.c
@@ -41,11 +41,11 @@ rpl_free (void *p)
   err[0] = errno;
   err[1] = errno;
   errno = 0;
-  GC_free (p);
+  free (p);
   errno = err[errno == 0];
 # else
   int err = errno;
-  GC_free (p);
+  free (p);
   errno = err;
 # endif
 }
