$NetBSD: patch-common_lib_Munin_Common_Defaults.pm,v 1.1 2022/04/04 11:45:33 jperkin Exp $

Initialize default paths for all Munin components.

--- common/lib/Munin/Common/Defaults.pm.orig	2019-05-09 03:45:43.000000000 +0000
+++ common/lib/Munin/Common/Defaults.pm
@@ -18,25 +18,25 @@ my $COMPONENT_ROOT = dirname(__FILE__) .
 our $DROPDOWNLIMIT     = 1;
 
 our $MUNIN_PREFIX     = '';
-our $MUNIN_CONFDIR    = "$COMPONENT_ROOT/t/config/";
+our $MUNIN_CONFDIR    = '@PKG_SYSCONFDIR@/';
 our $MUNIN_BINDIR     = '';
 our $MUNIN_SBINDIR    = '';
 our $MUNIN_DOCDIR     = '';
-our $MUNIN_LIBDIR     = '';
-our $MUNIN_HTMLDIR    = '';
-our $MUNIN_CGIDIR     = '';
+our $MUNIN_LIBDIR     = '@MUNIN_LIBDIR@';
+our $MUNIN_HTMLDIR    = '@MUNIN_WWWDIR@/munin/data';
+our $MUNIN_CGIDIR     = '@MUNIN_WWWDIR@/cgi-bin';
 our $MUNIN_CGITMPDIR     = '';
-our $MUNIN_DBDIR      = '';
-our $MUNIN_PLUGSTATE  = ''; 
+our $MUNIN_DBDIR      = '@MUNIN_DBDIR@';
+our $MUNIN_PLUGSTATE  = '@MUNIN_PLUGSTATE@';
 our $MUNIN_SPOOLDIR   = '';
 our $MUNIN_MANDIR     = '';
-our $MUNIN_LOGDIR     = "$COMPONENT_ROOT/log/";
-our $MUNIN_STATEDIR   = ''; 
+our $MUNIN_LOGDIR     = '@MUNIN_LOGDIR@/';
+our $MUNIN_STATEDIR   = '@MUNIN_STATEDIR@';
 our $MUNIN_USER       = getpwuid $UID;
 our $MUNIN_GROUP      = getgrgid $GID;
 our $MUNIN_PLUGINUSER = getpwuid $UID;
 our $MUNIN_VERSION    = 'svn';
-our $MUNIN_PERL       = '/usr/bin/perl';
+our $MUNIN_PERL       = '@PERL5@';
 our $MUNIN_PERLLIB    = '';
 our $MUNIN_GOODSH     = '';
 our $MUNIN_BASH       = '';
