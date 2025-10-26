$NetBSD: patch-src_mlock_mlock.c,v 1.1 2025/10/26 17:28:47 vins Exp $

Needed for write(2). 

--- src/mlock/mlock.c.orig	2011-07-23 00:19:57.000000000 +0000
+++ src/mlock/mlock.c
@@ -40,6 +40,7 @@
 #include <netdb.h>
 #include <ctype.h>
 #include <string.h>
+#include <unistd.h>
 
 #define LOCKTIMEOUT 5		/* lock timeout in minutes */
 #define LOCKPROTECTION 0664
