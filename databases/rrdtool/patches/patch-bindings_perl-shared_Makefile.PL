$NetBSD: patch-bindings_perl-shared_Makefile.PL,v 1.4 2017/07/27 18:31:20 adam Exp $

Fix Perl bindings.

--- bindings/perl-shared/Makefile.PL.orig	2015-04-20 23:12:18.000000000 +0900
+++ bindings/perl-shared/Makefile.PL	2015-08-16 22:00:55.000000000 +0900
@@ -40,9 +40,9 @@ if (($Config{'osname'} eq 'MSWin32' && $
 		for ($^O){
 			/linux/   && do{ $R = "-Wl,--rpath -Wl,$rp"};
 			/hpux/    && do{ $R = "+b$rp"};
-			/solaris/ && do{ $R = "-R$rp"};
-			/bsd/     && do{ $R = "-Wl,--rpath -Wl,$rp"};
-			/aix/     && do{ $R = "-blibpath:$rp"};
+			/solaris/ && do{ $R = "-Wl,-R$rp"};
+			/bsd/	  && do{ $R = "-Wl,-R$rp"};
+			/aix/	  && do{ $R = "-Wl,-blibpath:$rp"};
 		}
 	}
 
