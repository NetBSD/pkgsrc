#!/bin/sh
#
# $NetBSD: snort.sh,v 1.1.2.2 2003/03/04 01:02:27 salo Exp $
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
