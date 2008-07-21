#!/bin/sh
#
# $NetBSD: preludecorrelator.sh,v 1.1.1.1 2008/07/21 12:16:46 shannonjr Exp $
#

# PROVIDE: preludecorrelator
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="preludecorrelator"
procname="@PREFIX@/bin/prelude-correlator"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-correlator/prelude-correlator.conf"
start_precmd="correlator_precommand"
start_cmd="@PREFIX@/sbin/run-prelude-correlator --pidfile @PRELUDE_CORRELATOR_PID_DIR@/prelude-correlator.pid --daemon"
pidfile="@PRELUDE_CORRELATOR_PID_DIR@/prelude-correlator.pid"

correlator_precommand()
{
	/bin/mkdir -p @PRELUDE_CORRELATOR_PID_DIR@
	/usr/sbin/chown @PRELUDE_USER@:@PRELUDE_GROUP@ @PRELUDE_CORRELATOR_PID_DIR@
}

load_rc_config $name
run_rc_command "$1"
