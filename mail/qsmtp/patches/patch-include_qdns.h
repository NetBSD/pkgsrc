$NetBSD: patch-include_qdns.h,v 1.1 2020/03/06 20:50:24 schmonz Exp $

Avoid conflicting implicit definition of htonl() on NetBSD.

--- include/qdns.h.orig	2020-01-06 19:19:59.000000000 +0000
+++ include/qdns.h
@@ -4,6 +4,7 @@
 #ifndef QSMTP_DNS_H
 #define QSMTP_DNS_H
 
+#include <arpa/inet.h>
 #include <netinet/in.h>
 
 /** @enum mx_special_priorities
