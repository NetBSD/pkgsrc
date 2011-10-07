#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pflogger.sh,v 1.3 2011/10/07 22:37:05 shattered Exp $
#

# PROVIDE: preludepflogger
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="pflogger"
procname="@PREFIX@/bin/prelude-pflogger"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-pflogger/prelude-pflogger.conf"
start_precmd="pflogger_precommand"
start_cmd="@PREFIX@/sbin/run-prelude-pflogger --pidfile @PRELUDE_PFLOGGER_PID_DIR@/prelude-pflogger.pid"
pidfile="@PRELUDE_PFLOGGER_PID_DIR@/prelude-pflogger.pid"

pflogger_precommand()
{
	/bin/mkdir -p @PRELUDE_PFLOGGER_PID_DIR@
	/usr/sbin/chown @PRELUDE_USER@:@PRELUDE_GROUP@ @PRELUDE_PFLOGGER_PID_DIR@
}

load_rc_config $name
run_rc_command "$1"
