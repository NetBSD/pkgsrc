$NetBSD: patch-inc_Module_Install_RTx.pm,v 1.1 2015/09/23 11:46:57 joerg Exp $

--- inc/Module/Install/RTx.pm.orig	2013-07-10 19:41:51.000000000 +0000
+++ inc/Module/Install/RTx.pm
@@ -117,8 +117,6 @@ lexicons ::
     }
 
     my $postamble = << ".";
-install ::
-\t\$(NOECHO) \$(PERL) -MExtUtils::Install -e \"install({$args})\"
 .
 
     if ( $subdirs{var} and -d $RT::MasonDataDir ) {
