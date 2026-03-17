$NetBSD: patch-idea__spd.c,v 1.1 2026/03/17 08:10:24 nia Exp $

Fix implicit declaration of exit().

--- idea_spd.c.orig	2026-03-17 07:33:53.886403605 +0000
+++ idea_spd.c
@@ -64,6 +64,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #ifndef MSDOS
 #include <unistd.h>
 #else
