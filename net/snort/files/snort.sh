#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: snort.sh,v 1.2 2011/10/07 22:37:04 shattered Exp $
#

# PROVIDE: snort
# REQUIRE: DAEMON

. /etc/rc.subr

name="snort"
rcvar=$name
command="@PREFIX@/bin/${name}"
confdir="@PKG_SYSCONFDIR@"
required_files="$confdir/snort.conf $confdir/classification.config $confdir/reference.config"
command_args="-u @SNORT_USER@ -g @SNORT_GROUP@ -o -d -D -l /var/log/snort -c $confdir/snort.conf"

load_rc_config $name
run_rc_command "$1"
