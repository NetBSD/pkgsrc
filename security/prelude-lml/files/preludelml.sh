#!/bin/sh
#
# $NetBSD: preludelml.sh,v 1.1.1.1 2006/01/29 15:56:42 shannonjr Exp $
#

# PROVIDE: preludelml
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="preludelml"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-lml/prelude-lml.conf"
start_cmd="@PREFIX@/sbin/run-prelude-lml -d"
pidfile="@PRELUDE_LML_PID_DIR@/prelude-lml.pid"

load_rc_config $name
run_rc_command "$1"
