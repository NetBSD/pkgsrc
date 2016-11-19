$NetBSD: patch-libinterp_dldfcn_config-module.awk,v 1.2 2016/11/19 21:53:12 maya Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/config-module.awk.orig	2016-11-13 15:16:10.000000000 +0000
+++ libinterp/dldfcn/config-module.awk
@@ -39,7 +39,7 @@ BEGIN {
   print "## of symbolic links";
   print "";
   print "%.oct : %.la"
-  print "	$(AM_V_GEN)$(INSTALL_PROGRAM) libinterp/dldfcn/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
+  print "	$(AM_V_GEN)$(INSTALL_LIB) libinterp/dldfcn/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
   print ""
   print "else";
   print "";
