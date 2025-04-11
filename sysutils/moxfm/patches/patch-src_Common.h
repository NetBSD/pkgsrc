$NetBSD: patch-src_Common.h,v 1.1 2025/04/11 01:49:11 nia Exp $

Add missing include for exit() and friends.

--- src/Common.h.orig	2025-04-10 23:48:01.910135767 +0000
+++ src/Common.h
@@ -37,6 +37,7 @@
 #endif	/* _AIX */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h> /* just in case */
 #include <sys/stat.h>
 #include <dirent.h>
