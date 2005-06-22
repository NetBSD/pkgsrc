#!/bin/sh
#
# $NetBSD: proftpd.sh,v 1.2 2005/06/22 22:43:37 salo Exp $
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
