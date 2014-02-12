$NetBSD: patch-perl_Makefile.PL,v 1.1 2014/02/12 11:43:53 fhajny Exp $

Rename package files to avoid conflict with devel/libuuid (based
on Debian patches).

--- perl/Makefile.PL.orig	2007-01-01 18:13:18.000000000 +0000
+++ perl/Makefile.PL
@@ -33,9 +33,9 @@ use Config;
 use ExtUtils::MakeMaker;
 
 #   determine source directory
-my ($srcdir) = map { my $d = $_; $d =~ s/\/libuuid\.la$//; $d }
-               grep { -f $_ } ("../libuuid.la", glob("../*/libuuid.la"))
-    or die "no source directory found (where libuuid.la is located)";
+my ($srcdir) = map { my $d = $_; $d =~ s/\/libossp-uuid\.la$//; $d }
+               grep { -f $_ } ("../libossp-uuid.la", glob("../*/libossp-uuid.la"))
+    or die "no source directory found (where libossp-uuid.la is located)";
 
 #   determine extra build options
 my $compat = 0;
@@ -47,15 +47,15 @@ WriteMakefile(
     VERSION_FROM      => 'uuid.pm',
     ABSTRACT_FROM     => 'uuid.pod',
     PREREQ_PM         => {},
-    LIBS              => [ "-L$srcdir/.libs -L$srcdir -luuid" ],
+    LIBS              => [ "-L$srcdir/.libs -L$srcdir -lossp-uuid" ],
     DEFINE            => '',
     INC               => "-I. -I$srcdir",
     PM                => { 'uuid.pm'   => '$(INST_LIBDIR)/uuid.pm',
                            'uuid.pod'  => '$(INST_LIBDIR)/uuid.pod',
                            ($compat ? ('uuid_compat.pm'  => '$(INST_LIBDIR)/../Data/UUID.pm')  : ()),
                            ($compat ? ('uuid_compat.pod' => '$(INST_LIBDIR)/../Data/UUID.pod') : ()), },
-    MAN3PODS          => { 'uuid.pod' => '$(INST_MAN3DIR)/OSSP::uuid.3',
-                           ($compat ? ('uuid_compat.pod' => '$(INST_MAN3DIR)/Data::UUID.3') : ()), },
+    MAN3PODS          => { 'uuid.pod' => '$(INST_MAN3DIR)/OSSP::uuid.3pm',
+                           ($compat ? ('uuid_compat.pod' => '$(INST_MAN3DIR)/Data::UUID.3pm') : ()), },
     TYPEMAPS          => [ 'uuid.tm' ],
     test              => { TESTS => 'uuid.ts' . ($compat ? ' uuid_compat.ts' : '') },
     NO_META           => 1,
