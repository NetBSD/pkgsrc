$NetBSD: patch-ext_XS-APItest_Makefile.PL,v 1.1 2016/06/14 11:47:21 jperkin Exp $

Do not generate DTrace objects for objects which do not contain DTrace probes.

--- ext/XS-APItest/Makefile.PL.orig	2016-04-06 12:31:16.000000000 +0000
+++ ext/XS-APItest/Makefile.PL
@@ -3,7 +3,7 @@ use ExtUtils::MakeMaker;
 use ExtUtils::Constant 0.11 'WriteConstants';
 use Config;
 
-my $dtrace_o = $Config{dtraceobject} ? ' dtrace$(OBJ_EXT)' : '';
+my $dtrace_o = $Config{notdtraceobject} ? ' dtrace$(OBJ_EXT)' : '';
 
 WriteMakefile(
     'NAME'		=> 'XS::APItest',
@@ -49,7 +49,7 @@ sub MY::postamble
     package MY;
     my $post = shift->SUPER::postamble(@_);
     use Config;
-    return $post unless $Config{dtraceobject};
+    return $post unless $Config{notdtraceobject};
 
     # core.o is build using PERL_CORE, so picks up any dtrace probes
 
