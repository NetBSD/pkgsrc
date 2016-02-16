$NetBSD: patch-libinterp_dldfcn_config-module.awk,v 1.1 2016/02/16 04:21:40 dbj Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/config-module.awk.orig	2015-05-23 14:21:53.000000000 +0000
+++ libinterp/dldfcn/config-module.awk
@@ -39,7 +39,7 @@ BEGIN {
   print "## of symbolic links";
   print "";
   print "%.oct : %.la"
-  print "	$(AM_V_GEN)$(INSTALL_PROGRAM) dldfcn/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
+  print "	$(AM_V_GEN)$(INSTALL_LIB) dldfcn/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
   print ""
   print "else";
   print "";
