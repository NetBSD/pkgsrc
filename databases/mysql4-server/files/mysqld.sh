#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mysqld.sh,v 1.1.1.1 2003/12/20 16:00:43 martti Exp $
#

# PROVIDE: mysqld
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown

# Note: this needs NetBSD 1.6 or newer
#

. /etc/rc.subr

name="mysqld"
rcvar=$name
command="@PREFIX@/bin/mysqld_safe"
procname="@PREFIX@/libexec/${name}"
pidfile="@MYSQL_DATADIR@/`hostname`.pid"
start_cmd="mysqld_start"
required_files="@MYSQL_DATADIR@/mysql/host.frm"

mysqld_start()
{
	echo "Starting mysqld."
	ulimit -n 4096
	${command} ${mysqld_flags} &
}

load_rc_config $name
run_rc_command "$1"
