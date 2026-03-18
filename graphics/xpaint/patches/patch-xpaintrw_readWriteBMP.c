$NetBSD: patch-xpaintrw_readWriteBMP.c,v 1.1 2026/03/18 15:14:35 nia Exp $

Fix implicit declaration of bzero(3).

--- xpaintrw/readWriteBMP.c.orig	2026-03-18 14:26:40.326026936 +0000
+++ xpaintrw/readWriteBMP.c
@@ -10,6 +10,7 @@
  
 #include <stdio.h>
 #include <stdlib.h>
+#include <strings.h>
 
 #include <X11/Intrinsic.h>
 #include <X11/xpm.h>
