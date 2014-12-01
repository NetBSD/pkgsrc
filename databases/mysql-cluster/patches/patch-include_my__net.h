$NetBSD: patch-include_my__net.h,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

Define SHUT_RDWR for Irix 5.

--- include/my_net.h.orig	2013-01-22 16:54:49.000000000 +0000
+++ include/my_net.h
@@ -70,6 +70,15 @@ C_MODE_START
 #include <netdb.h>     /* getaddrinfo() & co */
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
