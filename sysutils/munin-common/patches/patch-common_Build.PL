$NetBSD: patch-common_Build.PL,v 1.1 2019/09/09 12:21:44 tm Exp $

Add missing module_name so that Munin::Common becomes a valid Perl Module.

--- common/Build.PL.orig	2019-01-17 12:03:08.506724040 +0000
+++ common/Build.PL
@@ -4,6 +4,7 @@ my $version = `../getversion`;
 chomp($version);

 my $build = Module::Build->new(
+    module_name    => 'Munin::Common',
     dist_name      => 'Munin::Common',
     dist_version   => $version,
     dist_author    => 'The Munin Team <munin-users@lists.sourceforge.net>',
