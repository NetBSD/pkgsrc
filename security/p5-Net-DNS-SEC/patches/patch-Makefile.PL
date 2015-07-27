$NetBSD: patch-Makefile.PL,v 1.1 2015/07/27 08:22:33 he Exp $

Don't install the RR modules, these are now after version 1.01
of Net::DNS part of that package instead.  This fixes CPAN problem
report https://rt.cpan.org/Public/Bug/Display.html?id=105698 while we
wait for 1.01 of Net::DNS::SEC.

--- Makefile.PL.orig	2015-02-11 13:34:24.000000000 +0000
+++ Makefile.PL
@@ -69,17 +69,6 @@ WriteMakefile(
 		'SEC/RSA.pm'	   => '$(INST_LIBDIR)/SEC/RSA.pm',
 		'SEC/Keyset.pm'	   => '$(INST_LIBDIR)/SEC/Keyset.pm',
 		'SEC/Private.pm'   => '$(INST_LIBDIR)/SEC/Private.pm',
-		'RR/CDNSKEY.pm'	   => '$(INST_LIBDIR)/RR/CDNSKEY.pm',
-		'RR/CDS.pm'	   => '$(INST_LIBDIR)/RR/CDS.pm',
-		'RR/DLV.pm'	   => '$(INST_LIBDIR)/RR/DLV.pm',
-		'RR/DNSKEY.pm'	   => '$(INST_LIBDIR)/RR/DNSKEY.pm',
-		'RR/DS.pm'	   => '$(INST_LIBDIR)/RR/DS.pm',
-		'RR/KEY.pm'	   => '$(INST_LIBDIR)/RR/KEY.pm',
-		'RR/NSEC.pm'	   => '$(INST_LIBDIR)/RR/NSEC.pm',
-		'RR/NSEC3.pm'	   => '$(INST_LIBDIR)/RR/NSEC3.pm',
-		'RR/NSEC3PARAM.pm' => '$(INST_LIBDIR)/RR/NSEC3PARAM.pm',
-		'RR/RRSIG.pm'	   => '$(INST_LIBDIR)/RR/RRSIG.pm',
-		'RR/SIG.pm'	   => '$(INST_LIBDIR)/RR/SIG.pm',
 		'KeysetStub.pm'	   => '$(INST_LIBDIR)/Keyset.pm',
 		},
 
