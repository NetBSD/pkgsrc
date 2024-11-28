$NetBSD: patch-DSO_dso.c,v 1.1 2024/11/28 10:03:32 jperkin Exp $

MIN() compat.

--- DSO/dso.c.orig	2024-11-28 09:30:11.045865201 +0000
+++ DSO/dso.c
@@ -66,6 +66,10 @@ extern uint16_t srp_random16(void);
 
 #include "mdns_strict.h"
 
+#ifndef MIN
+#define MIN(a, b) ((a) < (b) ? (a) : (b))
+#endif
+
 //*************************************************************************************************************
 // Remaining work TODO
 
