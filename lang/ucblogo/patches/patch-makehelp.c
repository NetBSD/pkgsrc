$NetBSD: patch-makehelp.c,v 1.2 2015/12/29 23:34:56 dholland Exp $

Use standard headers.

--- makehelp.c.orig	2013-07-17 14:25:25.000000000 +0000
+++ makehelp.c
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
 
