$NetBSD: patch-perl_OID_OID.xs,v 1.1 2022/10/18 12:01:52 adam Exp $

Adopt FreeBSD's patch to make this build with perl 5.24, ref.
https://svnweb.freebsd.org/ports/head/net-mgmt/net-snmp/files/patch-perl5.23?view=co
https://rt.perl.org/Public/Bug/Display.html?id=125907#txn-1363270
https://bugs.gentoo.org/show_bug.cgi?id=582368

--- perl/OID/OID.xs.orig	2016-06-06 13:52:38.000000000 +0000
+++ perl/OID/OID.xs
@@ -7,6 +7,10 @@
 #include "perl.h"
 #include "XSUB.h"
 
+#ifdef U64TYPE
+#define U64 U64pairU32
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-includes.h>
 
