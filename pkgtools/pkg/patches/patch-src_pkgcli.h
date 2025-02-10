$NetBSD: patch-src_pkgcli.h,v 1.1 2025/02/10 13:13:27 wiz Exp $

Do not define variables in a header file.

--- src/pkgcli.h.orig	2025-02-10 11:59:02.231352508 +0000
+++ src/pkgcli.h
@@ -37,12 +37,9 @@
 
 extern bool quiet;
 extern int nbactions;
-int nbactions;
 extern int nbdone;
-int nbdone;
 extern bool newpkgversion;
 extern int nbtodl;
-int nbtodl;
 
 /* pkg add */
 int exec_add(int, char **);
