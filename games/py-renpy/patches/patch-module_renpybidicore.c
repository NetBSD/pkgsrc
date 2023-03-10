$NetBSD: patch-module_renpybidicore.c,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* NetBSD has no alloca.h.

--- module/renpybidicore.c.orig	2022-04-12 03:01:04.396319900 +0000
+++ module/renpybidicore.c
@@ -8,9 +8,11 @@
 
 #include <stdlib.h>
 
+#if !defined(__NetBSD__)
 #ifndef alloca
 #include <alloca.h>
 #endif
+#endif
 
 
 PyObject *renpybidi_log2vis(PyObject *s, int *direction) {
