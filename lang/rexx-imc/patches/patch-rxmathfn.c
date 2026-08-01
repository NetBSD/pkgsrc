$NetBSD: patch-rxmathfn.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- rxmathfn.c.orig	2026-08-01 18:04:48.401417542 +0000
+++ rxmathfn.c
@@ -4,6 +4,7 @@
 #include<stdio.h>
 #include<math.h>
 #include<stdlib.h>
+#include<string.h>
 
 #if defined(Solaris) && !defined(__STDC__)
 #define const        /* Fix broken Solaris headers */
