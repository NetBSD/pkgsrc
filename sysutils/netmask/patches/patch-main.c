$NetBSD: patch-main.c,v 1.1 2024/10/10 17:47:42 nia Exp $

Use standard types.

--- main.c.orig	2024-10-10 17:46:30.119357320 +0000
+++ main.c
@@ -23,6 +23,7 @@
 #include <netdb.h>
 #include <netinet/in.h>
 #include <stdio.h>
+#include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
@@ -35,8 +36,8 @@
 #include "config.h"
 
 struct addrmask {
-  u_int32_t neta;
-  u_int32_t mask;
+  uint32_t neta;
+  uint32_t mask;
   struct addrmask *next;
   struct addrmask *prev;
 };
