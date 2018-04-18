$NetBSD: patch-gen.h,v 1.1 2018/04/18 08:42:16 he Exp $

If using modern C compiler, use header files instead of
attempting to predeclare C library functions.

--- gen.h.orig	1999-07-28 20:42:21.000000000 +0000
+++ gen.h
@@ -32,9 +32,15 @@
  *  Don't use protoypes here; increases conflicts with system include files.
  */
 
+#if defined(__STDC__) || defined(__sgi) || defined(_AIX) || defined(__alpha)
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
@@ -43,8 +49,9 @@ void exit();
 double fmod();	/* not in Sequent <math.h> */
 
 #if defined(__STDC__) || defined(__sgi) || defined(_AIX) || defined(__alpha)
-void *malloc(), *realloc();
-void *memset(), *memcpy();
+#include <unistd.h>
+#include <string.h>
+#include <stdlib.h>
 #else
 char *malloc(), *realloc();
 char *memset(), *memcpy();
