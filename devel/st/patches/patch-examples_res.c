$NetBSD: patch-examples_res.c,v 1.1 2017/11/30 10:05:34 gson Exp $

Provide _getshort() on Linux (tested on Debian 9)

--- examples/res.c.orig	2009-10-01 18:35:55.000000000 +0000
+++ examples/res.c
@@ -82,7 +82,7 @@
 #endif
 
 /* New in Solaris 7 */
-#if !defined(_getshort) && defined(ns_get16)
+#if (!defined(_getshort) && defined(ns_get16)) || __GLIBC__
 #define _getshort(cp) ns_get16(cp)
 #endif
 
