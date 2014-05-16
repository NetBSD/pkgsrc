$NetBSD: patch-lib_libedit_src_unvis.c,v 1.1 2014/05/16 12:49:42 ryoon Exp $

* Fix OpenBSD 5.5 build

--- lib/libedit/src/unvis.c.orig	2012-12-09 22:06:44.000000000 +0000
+++ lib/libedit/src/unvis.c
@@ -46,9 +46,11 @@ __RCSID("$NetBSD: unvis.c,v 1.32 2010/11
 #include <stdio.h>
 #include <vis.h>
 
+#if !defined(__OpenBSD__)
 #ifdef __weak_alias
 __weak_alias(strunvis,_strunvis)
 #endif
+#endif
 
 #if !HAVE_VIS
 /*
