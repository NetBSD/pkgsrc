$NetBSD: patch-gcc_gcc.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/gcc.c.orig	2013-01-14 16:35:23.000000000 +0000
+++ gcc/gcc.c
@@ -609,7 +609,7 @@ proper position among the other output f
 
 #ifndef LINK_PIE_SPEC
 #ifdef HAVE_LD_PIE
-#define LINK_PIE_SPEC "%{pie:-pie} "
+#define LINK_PIE_SPEC "%{pie:-pie} %{p|pg|nopie:-nopie} "
 #else
 #define LINK_PIE_SPEC "%{pie:} "
 #endif
