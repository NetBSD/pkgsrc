$NetBSD: patch-include_my_net.h,v 1.1.54.1 2019/09/08 16:55:18 bsiegert Exp $

* Define SHUT_RDWR for Irix 5.
* Stop useless warnings.

--- include/my_net.h.orig	2019-06-10 10:25:32.000000000 +0000
+++ include/my_net.h
@@ -70,14 +70,25 @@ C_MODE_START
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
   & Solaris64bit, in_addr_t is equivalent to uint32. And on Linux32bit too.
 */
 #ifndef HAVE_IN_ADDR_T
+#ifndef in_addr_t
 #define in_addr_t uint32
 #endif
+#endif
 
 
 C_MODE_END
