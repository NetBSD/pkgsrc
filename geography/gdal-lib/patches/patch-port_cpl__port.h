$NetBSD: patch-port_cpl__port.h,v 1.1 2024/06/13 16:54:50 jperkin Exp $

Avoid _LARGEFILE64_SOURCE on SunOS, it's an internal define.

--- port/cpl_port.h.orig	2024-06-13 15:35:44.135881093 +0000
+++ port/cpl_port.h
@@ -82,7 +82,7 @@
 #endif
 
 /*! @cond Doxygen_Suppress */
-#if defined(VSI_NEED_LARGEFILE64_SOURCE) && !defined(_LARGEFILE64_SOURCE)
+#if defined(VSI_NEED_LARGEFILE64_SOURCE) && !defined(_LARGEFILE64_SOURCE) && !defined(__sun)
 #define _LARGEFILE64_SOURCE 1
 #endif
 
