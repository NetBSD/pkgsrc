$NetBSD: patch-include_my_net.h,v 1.1.1.1 2011/04/25 21:12:53 adam Exp $

* Define SHUT_RDWR for Irix 5.

--- include/my_net.h.orig	2010-02-04 11:37:06.000000000 +0000
+++ include/my_net.h
@@ -64,6 +64,15 @@ C_MODE_START
 
 #endif
 
+#if defined(__sgi) && !defined(SHUT_RDWR)
+
+/*
+  IRIX 5 does not define SHUT_RDWR
+*/
+
+#define SHUT_RDWR 2
+#endif
+
 /*
   On OSes which don't have the in_addr_t, we guess that using uint32 is the best
   possible choice. We guess this from the fact that on HP-UX64bit & FreeBSD64bit
