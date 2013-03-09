$NetBSD: patch-asn.c,v 1.1 2013/03/09 10:25:28 tron Exp $

Fix build under Mac OS X. Based on this commit:

https://github.com/mackyle/mtr/commit/8348cfdc39694f0ada686b8277b75b3f72c6a47f

--- asn.c.orig	2013-02-23 15:13:40.000000000 +0000
+++ asn.c	2013-03-09 09:48:21.000000000 +0000
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
+#define BIND_8_COMPAT
 #include <arpa/nameser.h>
 #include <netdb.h>
 #include <netinet/in.h>
