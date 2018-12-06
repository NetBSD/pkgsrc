$NetBSD: patch-qmail-spp-spf-20091020.c,v 1.1 2018/12/06 00:07:33 schmonz Exp $

Adjust include path and IPv6 struct access.

--- qmail-spp-spf-20091020.c.orig	2018-12-05 23:27:39.000000000 +0000
+++ qmail-spp-spf-20091020.c
@@ -150,7 +150,7 @@
 #include <time.h>
 #include <arpa/inet.h>
 #include <unistd.h>
-#include "spf.h"
+#include "spf2/spf.h"
 
 #define LOG "qmail-spp-spf: "
 #define LOGR "qmail-spp-spf:%s: "
@@ -263,10 +263,17 @@ int random_ip_passes(SPF_request_t *spf_
     }
   else
     {
-      addr6.s6_addr32[0] = random();
-      addr6.s6_addr32[1] = random();
-      addr6.s6_addr32[2] = random();
-      addr6.s6_addr32[3] = random();
+#if defined (__linux__)
+# define v6member s6_addr32
+#elif (defined (sun) || defined (__sun)) && (defined (__SVR4) || defined(__svr4__))
+# define v6member _S6_un._S6_u32
+#else
+# define v6member __u6_addr.__u6_addr32
+#endif
+      addr6.v6member[0] = random();
+      addr6.v6member[1] = random();
+      addr6.v6member[2] = random();
+      addr6.v6member[3] = random();
 
       if (SPF_request_set_ipv6(spf_request, addr6))
 	{
