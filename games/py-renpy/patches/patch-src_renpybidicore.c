$NetBSD: patch-src_renpybidicore.c,v 1.1 2026/07/23 14:03:50 ryoon Exp $

* NetBSD has no alloca.h.

--- src/renpybidicore.c.orig	2023-06-13 02:11:15.133920000 +0000
+++ src/renpybidicore.c
@@ -4,9 +4,11 @@
 
 #include <stdlib.h>
 
+#if !defined(__NetBSD__)
 #ifndef alloca
 #include <alloca.h>
 #endif
+#endif
 
 #if PY_VERSION_HEX > 0x030300f0
 
