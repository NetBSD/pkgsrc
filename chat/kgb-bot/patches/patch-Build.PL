$NetBSD: patch-Build.PL,v 1.1.1.1 2013/10/20 14:16:16 tonnerre Exp $

Install into the appropriate directories.

--- Build.PL.orig	2013-08-17 07:41:14.000000000 +0000
+++ Build.PL
@@ -60,8 +60,13 @@ my $builder = My::Builder->new(
     },
     bindoc_dirs  => [qw(script sbin)],
     install_path => {
-        sbin => '/usr/sbin',
-        etc  => 'etc'
+        bin =>  $ENV{PREFIX} . '/bin',
+        sbin => $ENV{PREFIX} . '/sbin',
+        man5 => $ENV{PREFIX} . '/' . $ENV{PKGMANDIR} . '/man5/',
+        man7 => $ENV{PREFIX} . '/' . $ENV{PKGMANDIR} . '/man7/'
+    },
+    bin_files => {
+        'script/kgb-client'       => 'bin/kgb-client'
     },
     sbin_files => {
         'script/kgb-bot'          => 'sbin/kgb-bot',
@@ -69,13 +74,16 @@ my $builder = My::Builder->new(
         'script/kgb-split-config' => 'sbin/kgb-split-config',
     },
     etc_files => { 'etc/kgb.conf' => 'etc/kgb-bot/kgb.conf' },
-    man_files => { 'man5/*' => 'man5/' },
-    script_files => [ 'script/kgb-client' ],
+    man_files => {
+	'man5/*' => 'man5/',
+	'man7/*' => 'man7/'
+    },
     no_index => {
         directory => [ 'privinc' ],
     },
 );
 
+$builder->add_build_element('bin');
 $builder->add_build_element('sbin');
 $builder->add_build_element('etc');
 $builder->add_build_element('man');
