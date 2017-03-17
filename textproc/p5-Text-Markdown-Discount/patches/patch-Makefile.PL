$NetBSD: patch-Makefile.PL,v 1.1 2017/03/17 17:30:33 schmonz Exp $

cwrappers don't like piping to cpp. Work around this.

--- Makefile.PL.orig	2013-08-09 20:06:59.000000000 +0000
+++ Makefile.PL
@@ -61,7 +61,7 @@ sub MY::postamble {
     return sprintf('
 $(MYEXTLIB):
 	%s
-', qq{( cd $extdir; CC='cc -fPIC' sh configure.sh; make )\n});
+', qq{( cd $extdir; CC='cc -fPIC' AC_CPP_PROG='tradcpp' sh configure.sh; make )\n});
 }
 
 WriteMakefile(
