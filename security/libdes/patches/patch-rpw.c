$NetBSD: patch-rpw.c,v 1.1 2026/03/17 08:13:32 nia Exp $

Fix implicit declaration of exit.

--- rpw.c.orig	2026-03-17 07:32:09.961198911 +0000
+++ rpw.c
@@ -57,6 +57,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "des.h"
 
 int main(argc,argv)
