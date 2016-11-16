#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: couchdb.sh,v 1.1 2016/11/16 15:59:29 fhajny Exp $
#
# PROVIDE: couchdb
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="couchdb"
rcvar=$name
command="@PREFIX@/bin/couchdb"
command_args="&"
pidfile="@COUCH_RUNDIR@/couchdb.pid"
procname="@PREFIX@/couchdb/erts-@ERTS_VERSION@/bin/beam"
couchdb_user="@COUCH_USER@"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${couchdb_user} -c "${command} ${command_args}"
fi

if [ "$1" != "stop" -o "$1" != "status" ]; then
	sleep 2
	echo $(check_process $procname) > $pidfile
fi
