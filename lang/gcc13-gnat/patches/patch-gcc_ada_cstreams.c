$NetBSD: patch-gcc_ada_cstreams.c,v 1.2 2025/02/08 14:05:03 wiz Exp $

Add missing defines

--- gcc/ada/cstreams.c.orig	2024-05-21 10:47:37.000000000 +0300
+++ gcc/ada/cstreams.c
@@ -186,7 +186,8 @@
 	  *p = '\\';
     }
 
-#elif defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__DragonFly__) \
+  || defined (__OpenBSD__) || defined (__NetBSD__)
 
   /* Use realpath function which resolves links and references to . and ..
      on those Unix systems that support it. Note that GNU/Linux provides it but
@@ -255,7 +256,7 @@
 }
 
 #elif defined (__linux__) || defined (__sun__) || defined (__FreeBSD__) \
-  || defined (__APPLE__)
+  || defined (__APPLE__) || defined (__NetBSD__)
 /* section for platforms having ftello/fseeko */
 
 __int64
