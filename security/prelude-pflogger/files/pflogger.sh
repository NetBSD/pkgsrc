#!/bin/sh
#
# $NetBSD: pflogger.sh,v 1.1.1.1 2007/09/03 13:50:49 shannonjr Exp $
#

# PROVIDE: pflogger
# REQUIRE: pf NETWORKING

$_rc_subr_loaded . /etc/rc.subr

name="pflogger"
pflogger_user=_prelude
pflogger_=_prelude
procname="@PREFIX@/bin/prelude-pflogger"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-pflogger.conf"
start_precmd="pflogger_precommand"
pidfile="@PRELUDE_PFLOGGER_PID_DIR@/prelude-pflogger.pid"
start_cmd="${procname} --pidfile ${pidfile}"

pflogger_precommand()
{
	/bin/mkdir -p @PRELUDE_PFLOGGER_PID_DIR@
	/usr/sbin/chown @PRELUDE_USER@:@PRELUDE_GROUP@ @PRELUDE_PFLOGGER_PID_DIR@
}

load_rc_config $name
run_rc_command "$1"
