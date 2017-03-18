$NetBSD: patch-rs03-create.c,v 1.1 2017/03/18 13:54:24 adam Exp $

MMAP_FLAGS must be defined for all systems.

--- rs03-create.c.orig	2017-03-18 11:36:52.000000000 +0000
+++ rs03-create.c
@@ -51,6 +51,10 @@
   #define MMAP_FLAGS (MAP_SHARED) 
 #endif
 
+#ifdef SYS_UNKNOWN
+  #define MMAP_FLAGS (MAP_SHARED) 
+#endif
+
 #endif
 
 /***
