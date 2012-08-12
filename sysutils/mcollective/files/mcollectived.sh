#!/bin/sh
#
# $NetBSD: mcollectived.sh,v 1.1 2012/08/12 09:15:57 imil Exp $
#
# PROVIDE: mcollectived
# REQUIRE: DAEMON

. /etc/rc.subr

name="mcollectived"
rcvar=${name}
command="@PREFIX@/sbin/mcollectived"
required_files="@PKG_SYSCONFDIR@/mcollective/server.cfg"
pidfile="@VARBASE@/run/mcollectived.pid"
command_args="-p ${pidfile}"
procname="@RUBY@"

load_rc_config $name
run_rc_command "$1"
