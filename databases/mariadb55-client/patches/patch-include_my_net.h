$NetBSD: patch-include_my_net.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

* Define SHUT_RDWR for Irix 5.

--- include/my_net.h.orig	2015-02-13 12:07:01.000000000 +0000
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
