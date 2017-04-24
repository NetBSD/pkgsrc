$NetBSD: patch-src_rd.h,v 1.1 2017/04/24 12:20:37 fhajny Exp $

Unlock IOV_MAX on NetBSD and other guards.

--- src/rd.h.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/rd.h
@@ -40,6 +40,8 @@
 #endif
 #endif
 
+#define _XOPEN_SOURCE 600
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
