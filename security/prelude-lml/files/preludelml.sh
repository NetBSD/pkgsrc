#!/bin/sh
#
# $NetBSD: preludelml.sh,v 1.2 2006/01/31 10:46:31 shannonjr Exp $
#

# PROVIDE: preludelml
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="preludelml"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-lml/prelude-lml.conf"
start_precmd="preludelml_precommand"
start_cmd="@PREFIX@/sbin/run-prelude-lml -d --pidfile @PRELUDE_LML_PID_DIR@/prelude-lml.pid"
pidfile="@PRELUDE_LML_PID_DIR@/prelude-lml.pid"

preludelml_precommand()
{
	/bin/mkdir -p @PRELUDE_LML_PID_DIR@
	/usr/sbin/chown @PRELUDE_USER@:@PRELUDE_GROUP@ @PRELUDE_LML_PID_DIR@
}

load_rc_config $name
run_rc_command "$1"
