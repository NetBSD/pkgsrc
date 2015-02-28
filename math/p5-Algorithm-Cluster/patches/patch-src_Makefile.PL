$NetBSD: patch-src_Makefile.PL,v 1.1 2015/02/28 23:44:27 joerg Exp $

--- src/Makefile.PL.orig	2015-02-28 22:52:46.000000000 +0000
+++ src/Makefile.PL
@@ -2,13 +2,6 @@ use ExtUtils::MakeMaker;
 use Config;
 use POSIX;
 
-# Check if this is a 64 bit machine
-my $CCFLAGS = '';
-my $machine = (POSIX::uname())[4];
-if ($machine =~ /64/) {
-        $CCFLAGS = '-fPIC';
-}
-
 WriteMakefile(
 	NAME         => 'libcluster',
 	VERSION_FROM => '../perl/Cluster.pm',
@@ -17,7 +10,7 @@ WriteMakefile(
 	H	     => ['cluster.h'],
 	OBJECT       => 'cluster.o',
 	MYEXTLIB     => 'libcluster$(LIB_EXT)',
-	CCFLAGS      => $CCFLAGS,
+	CCFLAGS      => '-fPIC',
 	clean        => {'FILES' => 'libcluster$(LIBEEXT) $(OBJECT)'},
 );
 
