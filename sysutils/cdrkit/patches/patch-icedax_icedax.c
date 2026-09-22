$NetBSD: patch-icedax_icedax.c,v 1.1 2026/09/22 08:05:41 ryoon Exp $

--- icedax/icedax.c.orig	2026-08-22 08:58:13.291506852 +0000
+++ icedax/icedax.c
@@ -100,6 +100,7 @@
 #include <sys/resource.h>
 #endif
 #include <vadefs.h>
+#include <sys/wait.h>
 
 #include <usal/scsitransp.h>
 
