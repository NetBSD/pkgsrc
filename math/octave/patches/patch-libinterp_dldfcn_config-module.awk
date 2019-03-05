$NetBSD: patch-libinterp_dldfcn_config-module.awk,v 1.4 2019/03/05 11:11:12 ryoon Exp $

install .oct loadable modules with INSTALL_LIB to avoid stripping them

--- libinterp/dldfcn/config-module.awk.orig	2019-02-23 17:33:37.000000000 +0000
+++ libinterp/dldfcn/config-module.awk
@@ -55,7 +55,7 @@ BEGIN {
   print "## of symbolic links";
   print "";
   print "%.oct : %.la"
-  print "\t$(AM_V_GEN)$(INSTALL_PROGRAM) %reldir%/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
+  print "\t$(AM_V_GEN)$(INSTALL_LIB) %reldir%/.libs/$(shell $(SED) -n -e \"s/dlname='\\([^']*\\)'/\\1/p\" < $<) $@"
 
   for (i = 1; i <= nfiles; i++) {
     basename = files[i];
