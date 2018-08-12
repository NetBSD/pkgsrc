$NetBSD: patch-libinterp_dldfcn_config-module.awk,v 1.3 2018/08/12 08:33:55 maya Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/config-module.awk.orig	2018-08-09 18:20:32.000000000 +0000
+++ libinterp/dldfcn/config-module.awk
@@ -57,7 +57,7 @@ BEGIN {
   print "## of symbolic links";
   print "";
   print "%.oct : %.la"
-  print "\t$(AM_V_GEN)$(INSTALL_PROGRAM) %reldir%/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
+  print "\t$(AM_V_GEN)$(INSTALL_LIB) %reldir%/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
   print ""
   print "else";
   print "";
