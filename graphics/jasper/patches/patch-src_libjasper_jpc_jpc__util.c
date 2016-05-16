$NetBSD: patch-src_libjasper_jpc_jpc__util.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_util.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_util.c
@@ -109,7 +109,7 @@ int jpc_atoaf(char *s, int *numvalues, d
 	}
 
 	if (n) {
-		if (!(vs = jas_malloc(n * sizeof(double)))) {
+		if (!(vs = jas_alloc2(n, sizeof(double)))) {
 			return -1;
 		}
 
