$NetBSD: patch-sgetopt.h,v 1.1 2025/06/27 17:27:41 schmonz Exp $

Avoid "conflicting types for 'sgetoptmine'" on Illumos.

--- sgetopt.h.orig	2016-03-29 19:44:38.000000000 +0000
+++ sgetopt.h
@@ -14,7 +14,7 @@
 
 #include "subgetopt.h"
 
-extern int sgetoptmine(int,char **,char *);
+extern int sgetoptmine(int, char * const*, const char *);
 extern int sgetopterr;
 extern char *sgetoptprogname;
 
