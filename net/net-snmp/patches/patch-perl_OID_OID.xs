$NetBSD: patch-perl_OID_OID.xs,v 1.2 2026/01/11 05:08:00 wiz Exp $

Adopt FreeBSD's patch to make this build with perl 5.24, ref.
https://svnweb.freebsd.org/ports/head/net-mgmt/net-snmp/files/patch-perl5.23?view=co
https://rt.perl.org/Public/Bug/Display.html?id=125907#txn-1363270
https://bugs.gentoo.org/show_bug.cgi?id=582368

--- perl/OID/OID.xs.orig	2025-12-20 15:03:33.000000000 +0000
+++ perl/OID/OID.xs
@@ -8,6 +8,10 @@
 #include "XSUB.h"
 #pragma GCC diagnostic pop
 
+#ifdef U64TYPE
+#define U64 U64pairU32
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-includes.h>
 
