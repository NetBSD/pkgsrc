$NetBSD: patch-module_renpybidicore.c,v 1.2 2023/11/23 15:41:21 ryoon Exp $

* NetBSD has no alloca.h.

--- module/renpybidicore.c.orig	2023-06-13 02:11:15.133920000 +0000
+++ module/renpybidicore.c
@@ -4,9 +4,11 @@
 
 #include <stdlib.h>
 
+#if !defined(__NetBSD__)
 #ifndef alloca
 #include <alloca.h>
 #endif
+#endif
 
 #if PY_VERSION_HEX > 0x030300f0
 
