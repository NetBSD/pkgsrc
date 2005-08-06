#!/bin/sh
#
# $NetBSD: proftpd.sh,v 1.1.14.1 2005/08/06 22:17:34 salo Exp $
#

# PROVIDE: proftpd
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="proftpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/proftpd.conf"

load_rc_config $name
run_rc_command "$1"
