$NetBSD: patch-src_lib-ldap_ldap-private.h,v 1.1 2016/05/03 01:49:52 taca Exp $

Make sure to timeval structure is defined.

--- src/lib-ldap/ldap-private.h.orig	2016-04-26 13:01:21.000000000 +0000
+++ src/lib-ldap/ldap-private.h
@@ -3,6 +3,9 @@
 
 #include "iostream-ssl.h"
 #include "ldap-client.h"
+#if HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
 
 #include <ldap.h>
 
