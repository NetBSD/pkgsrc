$NetBSD: patch-lib_libedit_src_unvis.c,v 1.4 2015/09/17 17:12:19 joerg Exp $

* Fix OpenBSD 5.5 build

--- lib/libedit/src/unvis.c.orig	2012-12-09 22:06:44.000000000 +0000
+++ lib/libedit/src/unvis.c
@@ -46,9 +46,11 @@
 #include <stdio.h>
 #include <vis.h>
 
+#if !defined(__OpenBSD__)
 #ifdef __weak_alias
 __weak_alias(strunvis,_strunvis)
 #endif
+#endif
 
 #if !HAVE_VIS
 /*
