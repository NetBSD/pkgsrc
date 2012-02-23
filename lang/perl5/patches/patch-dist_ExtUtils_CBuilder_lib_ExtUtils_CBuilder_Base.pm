$NetBSD: patch-dist_ExtUtils_CBuilder_lib_ExtUtils_CBuilder_Base.pm,v 1.1 2012/02/23 13:00:23 fhajny Exp $

EU::CBuilder shouldn't override ccflags with CFLAGS (1/2)
https://rt.perl.org/rt3//Public/Bug/Display.html?id=89478
--- dist/ExtUtils-CBuilder/lib/ExtUtils/CBuilder/Base.pm.orig	2011-09-26 09:44:34.000000000 +0000
+++ dist/ExtUtils-CBuilder/lib/ExtUtils/CBuilder/Base.pm
@@ -40,11 +40,13 @@ sub new {
     $self->{config}{$k} = $v unless exists $self->{config}{$k};
   }
   $self->{config}{cc} = $ENV{CC} if defined $ENV{CC};
-  $self->{config}{ccflags} = $ENV{CFLAGS} if defined $ENV{CFLAGS};
+  $self->{config}{ccflags} = join(" ", $self->{config}{ccflags}, $ENV{CFLAGS})
+     if defined $ENV{CFLAGS};
   $self->{config}{cxx} = $ENV{CXX} if defined $ENV{CXX};
   $self->{config}{cxxflags} = $ENV{CXXFLAGS} if defined $ENV{CXXFLAGS};
   $self->{config}{ld} = $ENV{LD} if defined $ENV{LD};
-  $self->{config}{ldflags} = $ENV{LDFLAGS} if defined $ENV{LDFLAGS};
+  $self->{config}{ldflags} = join(" ", $self->{config}{ldflags}, $ENV{LDFLAGS})
+     if defined $ENV{LDFLAGS};
 
   unless ( exists $self->{config}{cxx} ) {
     my ($ccpath, $ccbase, $ccsfx ) = fileparse($self->{config}{cc}, qr/\.[^.]*/);
