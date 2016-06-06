$NetBSD: patch-perl_OID_Makefile.PL,v 1.1 2016/06/06 14:11:35 he Exp $

Adopt FreeBSD's patch to make this build with perl 5.24, ref.
https://svnweb.freebsd.org/ports/head/net-mgmt/net-snmp/files/patch-perl5.23?view=co
https://rt.perl.org/Public/Bug/Display.html?id=125907#txn-1363270
https://bugs.gentoo.org/show_bug.cgi?id=582368

--- perl/OID/Makefile.PL.orig	2014-12-08 20:23:22.000000000 +0000
+++ perl/OID/Makefile.PL
@@ -1,3 +1,4 @@
+package OID;
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
 
