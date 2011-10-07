#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: preludemanager.sh,v 1.4 2011/10/07 22:37:05 shattered Exp $
#

# PROVIDE: preludemanager
# REQUIRE: mysqld mail LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="preludemanager"
procname="@PREFIX@/bin/prelude-manager"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/prelude-manager/prelude-manager.conf"
start_precmd="preludemanager_precommand"
start_cmd="@PREFIX@/sbin/run-prelude-manager -d --pidfile @PRELUDE_MANAGER_PID_DIR@/prelude-manager.pid"
pidfile="@PRELUDE_MANAGER_PID_DIR@/prelude-manager.pid"

preludemanager_precommand()
{
	/bin/mkdir -p @PRELUDE_MANAGER_PID_DIR@
	/usr/sbin/chown @PRELUDE_USER@:@PRELUDE_GROUP@ @PRELUDE_MANAGER_PID_DIR@
	for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do
		if [ -S /tmp/mysql.sock ]; then
			break
		else
			sleep 1
			echo -n '.'
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
