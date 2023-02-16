$NetBSD: patch-gen.h,v 1.1 2023/02/16 17:59:49 he Exp $

Don't declare library functions on your own on NetBSD,
instead, use standard headers.

--- gen.h.orig	2000-10-31 22:53:40.000000000 +0000
+++ gen.h
@@ -32,9 +32,15 @@
  *  Don't use protoypes here; increases conflicts with system include files.
  */
 
+#if defined(__NetBSD__)
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
+#else
 char *getenv(), *getcwd();
 char *strcat(), *strncat(), *strchr(), *strrchr(), *strcpy(), *strncpy();
 void exit();
+#endif
 
 /* int functions are not explicitly defined -- use implicit definitions */
 /* This avoids conflicts on Solaris (at least) where strlen is a size_t fn */
@@ -43,11 +49,15 @@ void exit();
 double fmod();	/* not in Sequent <math.h> */
 
 #if defined(__STDC__) || defined(__sgi) || defined(_AIX) || defined(__alpha)
+# if !defined(__NetBSD__)
 void *malloc(), *realloc();
 void *memset(), *memcpy();
+# endif
 #else
+# if !defined(__NetBSD__)
 char *malloc(), *realloc();
 char *memset(), *memcpy();
+# endif
 #endif
 
 
