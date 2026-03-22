$NetBSD: patch-batch.c,v 1.1 2026/03/22 09:43:36 nia Exp $

Fix implicit declaration of exit.

--- batch.c.orig	2026-03-22 09:33:07.817190751 +0000
+++ batch.c
@@ -1,6 +1,7 @@
 #include <config.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
