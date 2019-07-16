$NetBSD: patch-lib_Module_Install_RTx.pm,v 1.1 2019/07/16 06:20:18 spz Exp $

fix up installpaths

--- lib/Module/Install/RTx.pm.orig	2018-03-02 20:05:16.000000000 +0000
+++ lib/Module/Install/RTx.pm
@@ -173,9 +173,9 @@ install ::
     # INSTALLDIRS=vendor should install manpages into /usr/share/man.
     # That is the default path in most distributions. Need input from
     # Redhat, Centos etc.
-    $self->makemaker_args( INSTALLVENDORMAN1DIR => "/usr/share/man/man1" );
-    $self->makemaker_args( INSTALLVENDORMAN3DIR => "/usr/share/man/man3" );
-    $self->makemaker_args( INSTALLVENDORARCH => "/usr/share/man" );
+    $self->makemaker_args( INSTALLVENDORMAN1DIR => "@PREFIX@/@PKGMANDIR@/man1" );
+    $self->makemaker_args( INSTALLVENDORMAN3DIR => "@PREFIX@/@PKGMANDIR@/man3" );
+    $self->makemaker_args( INSTALLVENDORARCH => "$RT::PluginPath/$name/$Config{api_versionstring}/$Config{archname}" );
 
     if (%has_etc) {
         print "For first-time installation, type 'make initdb'.\n";
