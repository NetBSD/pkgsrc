# $NetBSD: setup-pre.sh,v 1.3 2012/11/02 19:02:51 shattered Exp $
#
# This shell script is sourced by webmin's setup.sh to provide local
# overrides and defaults for configuration settings.
#

# This directory holds the example config files.  The strategy is to
# initially install all (example) config files into a separate examples
# directory and use INSTALL/DEINSTALL scripts to manage them.
#
config_dir="@WEBMIN_EGDIR@"

# Webmin run-time files directory
var_dir="@WEBMIN_VARDIR@"

# Path the the Perl interpreter
perl="@PERL5@"

port="10000"		# default webmin server port
login="admin"		# default admin user
password="password"	# default admin password
ssl=1			# always use SSL

atboot=0		# don't auto-configure to run at boot-time
noperlpath=		# fix up path to perl in scripts
nouninstall=1		# don't auto-create the uninstall script
nopostinstall=1		# don't auto-run the postinstall actions during setup
nostart=1		# don't auto-start the webmin server after setup
