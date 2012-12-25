$NetBSD: patch-src_fasthenry_mulSetup.c,v 1.1 2012/12/25 21:14:17 joerg Exp $

--- src/fasthenry/mulSetup.c.orig	2012-12-25 16:10:33.000000000 +0000
+++ src/fasthenry/mulSetup.c
@@ -37,6 +37,8 @@ operation of Software or Licensed Progra
 /* big changes for induct.c 7/2/92 */
 #include "induct.h"
 
+static void getnbrs(ssystem *sys);
+
 cube *cstack[1024];		/* Stack used in several routines. */
 
 /*
@@ -932,8 +934,7 @@ int num_lexact, num_mexact;
 Find all the nearest neighbors.
 At the bottom level, get neighbors due to a parents being exact.
 */
-getnbrs(sys)
-ssystem *sys;
+static void getnbrs(ssystem *sys)
 {
 cube *nc, *np, *****cubes = sys->cubes;
 int depth = sys->depth;
