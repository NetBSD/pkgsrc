$NetBSD: patch-cmu-snmp_snmp_asn1.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- cmu-snmp/snmp/asn1.c~	1998-05-29 13:46:30.000000000 +0000
+++ cmu-snmp/snmp/asn1.c
@@ -36,6 +36,7 @@
 #endif /* HAVE_CONFIG_H */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #ifdef WIN32
 #include <memory.h>
