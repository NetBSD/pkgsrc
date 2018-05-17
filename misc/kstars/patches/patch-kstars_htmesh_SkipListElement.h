$NetBSD: patch-kstars_htmesh_SkipListElement.h,v 1.1 2018/05/17 11:18:50 jperkin Exp $

Fix __sun check.

--- kstars/htmesh/SkipListElement.h.orig	2014-09-19 05:39:42.000000000 +0000
+++ kstars/htmesh/SkipListElement.h
@@ -20,7 +20,7 @@
 #ifdef _WIN32
 #define KEY_MAX _I64_MAX
 #else
-#  if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || ( defined(__SUNPRO_CC) && defined(__sun) )
+#  if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun)
 #    define KEY_MAX LLONG_MAX
 #  else
 #    define KEY_MAX LONG_LONG_MAX
