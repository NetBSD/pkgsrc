$NetBSD: patch-xputenv.c,v 1.1 2013/02/05 07:54:52 wiz Exp $

Include stdlib.h for putenv to avoid
[...]/print/web2c/work/.buildlink/lib/libkpathsea.so: warning: warning: reference to compatibility putenv(); include <stdlib.h> for correct reference

--- xputenv.c.orig	2010-02-15 08:19:27.000000000 +0000
+++ xputenv.c
@@ -20,13 +20,7 @@
 #include <kpathsea/config.h>
 #include <kpathsea/types.h>
 
-#ifdef WIN32
 #include <stdlib.h>
-#else
-#if !HAVE_DECL_PUTENV
-extern int putenv (char* entry);
-#endif
-#endif /* not WIN32 */
 
 /*
  * We have different arguments from the "standard" function.  A separate
