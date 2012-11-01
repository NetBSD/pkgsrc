$NetBSD: patch-lookup.c,v 1.1 2012/11/01 19:49:32 joerg Exp $

--- lookup.c.orig	2012-10-30 19:09:40.000000000 +0000
+++ lookup.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <string.h>
 #include "lookup.h"
 
 static
