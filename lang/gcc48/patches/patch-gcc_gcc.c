$NetBSD: patch-gcc_gcc.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/gcc.c.orig	2014-03-23 11:30:57.000000000 +0000
+++ gcc/gcc.c
@@ -661,7 +661,7 @@ proper position among the other output f
 
 #ifndef LINK_PIE_SPEC
 #ifdef HAVE_LD_PIE
-#define LINK_PIE_SPEC "%{pie:-pie} "
+#define LINK_PIE_SPEC "%{pie:-pie} %{p|pg|nopie:-nopie} "
 #else
 #define LINK_PIE_SPEC "%{pie:} "
 #endif
