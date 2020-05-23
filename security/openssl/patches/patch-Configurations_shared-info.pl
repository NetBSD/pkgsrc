$NetBSD: patch-Configurations_shared-info.pl,v 1.1 2020/05/23 10:32:06 jperkin Exp $

Specifying --libdir makes LIBDIR empty and breaks library names.

--- Configurations/shared-info.pl.orig	2020-04-21 12:22:39.000000000 +0000
+++ Configurations/shared-info.pl
@@ -44,7 +44,7 @@ my %shared_info;
     'darwin-shared' => {
         module_ldflags        => '-bundle',
         shared_ldflag         => '-dynamiclib -current_version $(SHLIB_VERSION_NUMBER) -compatibility_version $(SHLIB_VERSION_NUMBER)',
-        shared_sonameflag     => '-install_name $(INSTALLTOP)/$(LIBDIR)/',
+        shared_sonameflag     => '-install_name $(libdir)/',
     },
     'cygwin-shared' => {
         shared_ldflag         => '-shared -Wl,--enable-auto-image-base',
