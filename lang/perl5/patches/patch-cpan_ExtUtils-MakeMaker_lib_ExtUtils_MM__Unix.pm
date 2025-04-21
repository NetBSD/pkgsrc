$NetBSD: patch-cpan_ExtUtils-MakeMaker_lib_ExtUtils_MM__Unix.pm,v 1.4 2025/04/21 20:55:34 wiz Exp $

* Ignore installed packlist when creating new packlist.

--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm.orig	2021-05-13 17:40:25.661784701 +0900
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm	2021-05-13 17:40:29.734082886 +0900
@@ -2351,7 +2349,7 @@ pure_vendor_install :: all
 	$(NOECHO) $(MOD_INSTALL) \
 };
     push @m,
-q{		read "}.$self->catfile('$(VENDORARCHEXP)','auto','$(FULLEXT)','.packlist').q{" \
+q{		read "" \
 		write "}.$self->catfile('$(DESTINSTALLVENDORARCH)','auto','$(FULLEXT)','.packlist').q{" \
 } unless $self->{NO_PACKLIST};
 
