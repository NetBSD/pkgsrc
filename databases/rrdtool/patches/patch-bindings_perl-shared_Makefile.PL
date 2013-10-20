$NetBSD: patch-bindings_perl-shared_Makefile.PL,v 1.1 2013/10/20 18:18:52 joerg Exp $

--- bindings/perl-shared/Makefile.PL.orig	2013-10-16 20:05:57.000000000 +0000
+++ bindings/perl-shared/Makefile.PL
@@ -30,9 +30,9 @@ if (($Config{'osname'} eq 'MSWin32' && $
 		for ($^O){
 			/linux/   && do{ $R = "-Wl,--rpath -Wl,$rp"};
 			/hpux/    && do{ $R = "+b$rp"};
-			/solaris/ && do{ $R = "-R$rp"};
-			/bsd/     && do{ $R = "-R$rp"};
-			/aix/     && do{ $R = "-blibpath:$rp"};
+			/solaris/ && do{ $R = "-Wl,-R$rp"};
+			/bsd/     && do{ $R = "-Wl,-R$rp"};
+			/aix/     && do{ $R = "-Wl,-blibpath:$rp"};
 		}
 	}
 
