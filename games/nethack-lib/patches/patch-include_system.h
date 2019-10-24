$NetBSD: patch-include_system.h,v 1.2 2019/10/24 11:51:23 pho Exp $

Fix for NetBSD.

--- include/system.h.orig	2019-05-08 07:00:15.000000000 +0000
+++ include/system.h
@@ -82,11 +82,11 @@ typedef long off_t;
 #if !defined(__SC__) && !defined(LINUX)
 E long NDECL(random);
 #endif
-#if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) \
+#if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__) && !defined(__APPLE__)) \
     || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 #else
-#if !defined(bsdi) && !defined(__FreeBSD__)
+#if !defined(bsdi) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__) && !defined(__APPLE__)
 E int FDECL(srandom, (unsigned int));
 #endif
 #endif
@@ -141,7 +141,7 @@ E void FDECL(perror, (const char *));
 E void FDECL(qsort, (genericptr_t, size_t, size_t,
                      int (*)(const genericptr, const genericptr)));
 #else
-#if defined(BSD) || defined(ULTRIX)
+#if defined(BSD) || defined(ULTRIX) && !defined(__NetBSD__)
 E int qsort();
 #else
 #if !defined(LATTICE) && !defined(AZTEC_50)
@@ -431,7 +431,7 @@ E size_t FDECL(strlen, (const char *));
 #ifdef HPUX
 E unsigned int FDECL(strlen, (char *));
 #else
-#if !(defined(ULTRIX_PROTO) && defined(__GNUC__))
+#if !(defined(ULTRIX_PROTO) && defined(__GNUC__)) && !defined(__NetBSD__)
 E int FDECL(strlen, (const char *));
 #endif
 #endif /* HPUX */
@@ -486,9 +486,14 @@ E char *sprintf();
 #if !defined(SVR4) && !defined(apollo)
 #if !(defined(ULTRIX_PROTO) && defined(__GNUC__))
 #if !(defined(SUNOS4) && defined(__STDC__)) /* Solaris unbundled cc (acc) */
+#if 0
 E int FDECL(vsprintf, (char *, const char *, va_list));
 E int FDECL(vfprintf, (FILE *, const char *, va_list));
 E int FDECL(vprintf, (const char *, va_list));
+#else
+#include <stdarg.h>
+#include <stdio.h>
+#endif
 #endif
 #endif
 #endif
@@ -542,7 +547,7 @@ E struct tm *FDECL(localtime, (const tim
 
 #if defined(ULTRIX) || (defined(BSD) && defined(POSIX_TYPES))          \
     || defined(SYSV) || defined(MICRO) || defined(VMS) || defined(MAC) \
-    || (defined(HPUX) && defined(_POSIX_SOURCE))
+    || (defined(HPUX) && defined(_POSIX_SOURCE)) || defined(__NetBSD__)
 E time_t FDECL(time, (time_t *));
 #else
 E long FDECL(time, (time_t *));
