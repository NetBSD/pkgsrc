$NetBSD: patch-main.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- main.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ main.c
@@ -1,5 +1,6 @@
 #include "env.h"
 #include "exit.h"
+#include "prot.h"
 #include "scan.h"
 
 extern void doit(void);
