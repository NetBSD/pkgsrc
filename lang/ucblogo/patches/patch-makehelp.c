$NetBSD: patch-makehelp.c,v 1.1 2013/07/18 12:05:09 joerg Exp $

--- makehelp.c.orig	2013-07-17 14:25:25.000000000 +0000
+++ makehelp.c
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
 
