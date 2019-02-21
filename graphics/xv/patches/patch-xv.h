$NetBSD: patch-xv.h,v 1.1 2019/02/21 14:32:32 tsutsui Exp $

- don't declare errno and sys_errlist
- use strerror
- use getcwd, not getwd

--- xv.h.orig	2019-02-21 14:07:38.801848956 +0000
+++ xv.h
@@ -139,9 +139,7 @@
 #endif
 
 
-#if defined(__FreeBSD__)
-#  include <sys/param.h>
-#endif
+#include <sys/param.h>
 
 
 /* include files */
@@ -160,7 +158,7 @@
 #ifndef VMS
 #  include <errno.h>
 #  ifndef __NetBSD__
-#    if !(defined __GLIBC__ && __GLIBC__ >= 2)
+#    if !(defined(BSD) && (BSD >= 199103)) && !(defined __GLIBC__ && __GLIBC__ >= 2)
        extern int   errno;         /* SHOULD be in errno.h, but often isn't */
        extern char *sys_errlist[]; /* this too... */
 #    endif
@@ -172,7 +170,7 @@
 #ifdef VMS
 #  define ERRSTR(x) strerror(x, vaxc$errno)
 #else
-#  if defined(__BEOS__) || defined(__linux__) /* or all modern/glibc systems? */
+#  if defined(__BEOS__) || defined(__linux__) || defined(__INTERIX) || defined(__sun) /* or all modern/glibc systems? */
 #    define ERRSTR(x) strerror(x)
 #  else
 #    define ERRSTR(x) sys_errlist[x]
@@ -208,7 +206,9 @@
 #  if defined(hp300) || defined(hp800) || defined(NeXT)
 #    include <sys/malloc.h>    /* it's in "sys" on HPs and NeXT */
 #  else
-#    include <malloc.h>
+#    ifndef __DARWIN__
+#      include <malloc.h>
+#    endif
 #  endif
 #endif
 
@@ -392,7 +392,7 @@
 #  endif
 #endif
 
-#if (defined(SYSV) || defined(SVR4) || defined(linux)) && !defined(USE_GETCWD)
+#if (defined(SYSV) || defined(SVR4) || defined(linux) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)) && !defined(USE_GETCWD)
 #  define USE_GETCWD
 #endif
 
