$NetBSD: patch-sorted-hashtable.c,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Use standard compiler macros

--- sorted-hashtable.c.orig	2018-11-08 03:33:50 UTC
+++ sorted-hashtable.c
@@ -23,11 +23,9 @@
 #include <stdlib.h>
 #include <string.h>
 
-#ifndef MACOS
-#ifndef FREEBSD
+#if !defined(__FreeBSD__) && !defined(__APPLE__)
 #include <malloc.h>
 #endif
-#endif
 
 #include<math.h>
 #include"core.h"
