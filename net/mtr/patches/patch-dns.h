$NetBSD: patch-dns.h,v 1.1 2013/03/09 10:25:28 tron Exp $

Fix build under Mac OS X. Based on this commit:

https://github.com/mackyle/mtr/commit/8348cfdc39694f0ada686b8277b75b3f72c6a47f

--- dns.h.orig	2013-02-23 15:13:40.000000000 +0000
+++ dns.h	2013-03-09 10:21:42.000000000 +0000
@@ -17,7 +17,7 @@
 */
 
 #include <netinet/in.h>
-
+#include <resolv.h>
 
 /*  Prototypes for dns.c  */
 
@@ -27,10 +27,10 @@
 #ifdef ENABLE_IPV6
 int dns_waitfd6(void);
 void dns_ack6(void);
-#ifdef BSD
+#if defined(BSD) || defined(__APPLE__)
 /* __res_state_ext is missing on many (most?) BSD systems
    - this should probably be handled by autoconf */
-#ifndef __res_state_ext
+#if !defined(__res_state_ext) || defined(__APPLE__)
 struct __res_state_ext {
 	union res_sockaddr_union nsaddrs[MAXNS];
 	struct sort_list {
