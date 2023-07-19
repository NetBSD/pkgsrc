#!/bin/sh
#
# $NetBSD: supervisord.sh,v 1.1 2023/07/19 12:48:22 wiz Exp $
#
# PROVIDE: supervisord
# REQUIRE: DAEMON

. /etc/rc.subr

name="supervisord"
rcvar=${name}
command="@PREFIX@/bin/supervisord-@PYVERSSUFFIX@"
command_interpreter="@PREFIX@/bin/python@PYVERSSUFFIX@"
required_files="@PREFIX@/etc/supervisord.conf"
pidfile="/var/run/supervisord.pid"
supervisord_flags="-c @PREFIX@/etc/supervisord.conf"

load_rc_config $name
run_rc_command "$1"
