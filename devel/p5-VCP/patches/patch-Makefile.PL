$NetBSD: patch-Makefile.PL,v 1.1 2012/06/21 09:12:44 obache Exp $

* This patch to p5-VCP-autrijus disables the unneccessary
  run of bin/gentrevml before "make", because it is time
  consuming and is not used at all.
  (taken from FreeBSD ports/devel/p5-VCP-autrijus)

--- Makefile.PL.orig	2005-01-10 12:39:47.000000000 +0000
+++ Makefile.PL
@@ -212,7 +212,7 @@ sub MY::postamble {
    my $self = shift ;
    return join(
       "",
-      "\npure_all :: $io_test_files\n",
+      "\n#pure_all :: $io_test_files\n",
       map(
          "\n$_ : bin/gentrevml\n$io_scheme_revmls{$_}",
 	 sort keys %io_scheme_revmls
