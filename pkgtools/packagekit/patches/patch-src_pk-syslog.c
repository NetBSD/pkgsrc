$NetBSD: patch-src_pk-syslog.c,v 1.1 2013/06/23 18:21:41 jperkin Exp $

Add include for LOG_AUTHPRIV.

--- src/pk-syslog.c.orig	2008-12-04 13:45:11.000000000 +0000
+++ src/pk-syslog.c
@@ -27,6 +27,10 @@
 
 #include "egg-debug.h"
 
+#ifdef __sun
+#include <netinet/ip_compat.h>
+#endif
+
 #define PK_SYSLOG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PK_TYPE_SYSLOG, PkSyslogPrivate))
 
 struct PkSyslogPrivate
