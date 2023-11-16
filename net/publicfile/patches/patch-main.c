$NetBSD: patch-main.c,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Add missing includes.

--- main.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ main.c
@@ -1,5 +1,6 @@
 #include "env.h"
 #include "exit.h"
+#include "prot.h"
 #include "scan.h"
 
 extern void doit(void);
