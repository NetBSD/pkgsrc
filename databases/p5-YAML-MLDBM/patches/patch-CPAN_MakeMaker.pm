$NetBSD: patch-CPAN_MakeMaker.pm,v 1.1 2015/06/27 18:42:42 joerg Exp $

--- CPAN/MakeMaker.pm.orig	2015-06-24 20:36:16.000000000 +0000
+++ CPAN/MakeMaker.pm
@@ -36,15 +36,14 @@ sub WriteMakefile {
     determine_VERSION()
       unless defined $ARGS{VERSION} or defined $ARGS{VERSION_FROM};
     determine_CLEAN_FILES() 
-      if defined $main::CLEAN_FILES or
-         defined @main::CLEAN_FILES;
+      if defined $main::CLEAN_FILES or @main::CLEAN_FILES;
     $ARGS{ABSTRACT} = $main::ABSTRACT 
       if defined $main::ABSTRACT and $] >= 5.005;
     $ARGS{AUTHOR} = $main::AUTHOR 
       if defined $main::AUTHOR and $] >= 5.005;
-    $ARGS{PREREQ_PM} = \%main::PREREQ_PM if defined %main::PREREQ_PM;
-    $ARGS{PL_FILES} = \%main::PL_FILES if defined %main::PL_FILES;
-    $ARGS{EXE_FILES} = \@main::EXE_FILES if defined @main::EXE_FILES;
+    $ARGS{PREREQ_PM} = \%main::PREREQ_PM if %main::PREREQ_PM;
+    $ARGS{PL_FILES} = \%main::PL_FILES if %main::PL_FILES;
+    $ARGS{EXE_FILES} = \@main::EXE_FILES if @main::EXE_FILES;
 
     my %Args = (%ARGS, %args);
     ExtUtils::MakeMaker::WriteMakefile(%Args);
@@ -119,7 +118,7 @@ sub determine_CLEAN_FILES {
             $clean_files = $main::CLEAN_FILES;
         }
     }
-    if (defined(@main::CLEAN_FILES)) {
+    if (@main::CLEAN_FILES) {
         $clean_files = join ' ', ($clean_files, @main::CLEAN_FILES);
     }
     $clean_files = join ' ', ($clean_files, @CLEAN);
