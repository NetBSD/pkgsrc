$NetBSD: patch-cf_roken-frag.m4,v 1.1 2014/05/16 12:49:42 ryoon Exp $

* OpenBSD's vis.h requires stdlib.h

--- cf/roken-frag.m4.orig	2012-12-09 22:06:44.000000000 +0000
+++ cf/roken-frag.m4
@@ -97,6 +97,7 @@ AC_HAVE_TYPE([uintptr_t],[#ifdef HAVE_ST
 
 dnl Sunpro 5.2 has a vis.h which is something different.
 AC_CHECK_HEADERS(vis.h, , , [
+#include <stdlib.h>
 #include <vis.h>
 #ifndef VIS_SP
 #error invis
