$NetBSD: patch-Makefile.PL,v 1.2 2016/09/20 11:40:27 mef Exp $

Remove unnecessary (and yet harmful) configuration check.
In pkgsrc environment, it should always pass.    
    
--- Makefile.PL.orig	2015-09-27 20:56:20.000000000 +0900
+++ Makefile.PL	2016-09-20 20:26:33.000000000 +0900
@@ -24,20 +24,13 @@ for my $config_name (qw(ft_config)) {
             %{ $config->{$config_name} },
             %header_config,
     );
-
-    # test the configuration
-    if( check_lib( %checklib_config ) ) {
         $working_config_name = $config_name;
-    }
 }
 
 # if none of the tried configurations work, use the default
 $working_config_name = 'default' if not defined $working_config_name;
 
 my $working_config = $config->{$working_config_name};
-if( !exists $working_config->{LIBS} && exists $working_config->{lib} ) {
-    $working_config->{LIBS} = "-l$working_config->{lib}";
-}
 
 # MakeMaker build flags
 my %MakeMakerFlags = (
@@ -49,12 +42,6 @@ print STDERR "Build config: $working_con
 print STDERR "Build flag LIB: $MakeMakerFlags{LIBS}\n";
 print STDERR "Build flag INC: $MakeMakerFlags{INC}\n";
 
-# finally use check_lib_or_exit so that it gives appropriate warnings to the user
-check_lib_or_exit(
-    %MakeMakerFlags,
-    %header_config,
-);
-
 WriteMakefile(
     NAME               => 'Font::FreeType',
     AUTHOR             => 'Geoff Richards <qef@laxan.com>',
