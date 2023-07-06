$NetBSD: patch-libmailutils_base_hostname.c,v 1.1 2023/07/06 17:59:38 vins Exp $

Add missing includes.

--- libmailutils/base/hostname.c.orig	2023-05-01 09:46:38.000000000 +0000
+++ libmailutils/base/hostname.c
@@ -24,6 +24,8 @@
 #include <errno.h>
 #include <string.h>
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <mailutils/alloc.h>
 
 #ifndef MAXHOSTNAMELEN
