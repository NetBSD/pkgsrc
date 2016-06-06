$NetBSD: patch-perl_agent_Makefile.PL,v 1.2 2016/06/06 14:11:35 he Exp $

Adopt FreeBSD's patch to make this build with perl 5.24, ref.
https://svnweb.freebsd.org/ports/head/net-mgmt/net-snmp/files/patch-perl5.23?view=co
https://rt.perl.org/Public/Bug/Display.html?id=125907#txn-1363270
https://bugs.gentoo.org/show_bug.cgi?id=582368

--- perl/agent/Makefile.PL.orig	2016-06-06 13:52:38.000000000 +0000
+++ perl/agent/Makefile.PL
@@ -1,3 +1,4 @@
+package agent;
 use ExtUtils::MakeMaker;
 require 5;
 use Config;
