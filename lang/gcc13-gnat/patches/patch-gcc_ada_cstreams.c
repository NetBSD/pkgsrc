$NetBSD: patch-gcc_ada_cstreams.c,v 1.1 2024/03/08 12:02:33 wiz Exp $

Add missing defines

--- gcc/ada/cstreams.c.orig	2021-08-28 18:42:21.323680378 +0000
+++ gcc/ada/cstreams.c	2021-08-28 18:43:48.045445919 +0000
@@ -188,7 +188,8 @@
 	  *p = '\\';
     }
 
-#elif defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__DragonFly__) \
+  || defined (__OpenBSD__) || defined (__NetBSD__)
 
   /* Use realpath function which resolves links and references to . and ..
      on those Unix systems that support it. Note that GNU/Linux provides it but
@@ -270,7 +271,7 @@
 }
 
 #elif defined (__linux__) || defined (__sun__) || defined (__FreeBSD__) \
-  || defined (__APPLE__)
+  || defined (__APPLE__) || defined (__NetBSD__)
 /* section for platforms having ftello/fseeko */
 
 __int64
