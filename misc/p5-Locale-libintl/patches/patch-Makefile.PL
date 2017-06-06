$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 08:02:55 ryoon Exp $

* Fix for Perl 5.26.0
  https://rt.cpan.org/Public/Bug/Display.html?id=120446

--- Makefile.PL.orig	2016-05-16 19:31:26.000000000 +0000
+++ Makefile.PL
@@ -199,7 +199,7 @@ sub tools_other 
 	my $fragment = $self->SUPER::tools_other (@_);
 
 	$fragment =~ s/^MOD_INSTALL\s*=\s*(.*?)-MExtUtils::Install
-		/MOD_INSTALL =$1-MMyInstall/msx;
+		/MOD_INSTALL =$1-I. -MMyInstall/msx;
 
 	return $fragment;
 }
