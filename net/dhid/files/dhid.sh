#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dhid.sh,v 1.4 2002/09/23 07:07:03 grant Exp $
#
# PROVIDE: dhid
# REQUIRE: NETWORK

. /etc/rc.subr

name="dhid"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dhid.conf"

load_rc_config $name
run_rc_command "$1"
