$NetBSD: patch-title.c,v 1.1 2020/11/20 13:50:23 nia Exp $

Include unistd.h for close().

--- title.c.orig	2008-03-05 21:58:16.000000000 +0000
+++ title.c
@@ -5,6 +5,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #ifdef HAVE_FCNTL_H
 # include <fcntl.h>
 #endif
