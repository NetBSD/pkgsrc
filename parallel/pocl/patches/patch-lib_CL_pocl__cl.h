$NetBSD: patch-lib_CL_pocl__cl.h,v 1.1 2025/05/25 13:01:56 adam Exp $

alloca.h is not portable.

--- lib/CL/pocl_cl.h.orig	2025-05-25 07:35:36.948949856 +0000
+++ lib/CL/pocl_cl.h
@@ -32,7 +32,7 @@
 #include <errno.h>
 #include <stdio.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <stdlib.h>
 #elif defined(_WIN32)
 #include <malloc.h>
