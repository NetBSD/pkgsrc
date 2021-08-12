#!/bin/sh
#
# $NetBSD: mariadb.sh,v 1.3 2021/08/12 10:51:31 nia Exp $
#
# PROVIDE: mariadb mysqld
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mariadb"
rcvar=${name}
procname="@PREFIX@/sbin/mariadbd"
command="@PREFIX@/bin/mariadbd-safe"
command_args="--pid-file=@VARBASE@/run/mariadb/mariadb.pid"
command_args="${command_args} --user=@MARIADB_USER@"
command_args="${command_args} --datadir=@MARIADB_DATADIR@"
command_args="${command_args} --log-error=@VARBASE@/log/mariadb/error.log &"
extra_commands="initdb"
initdb_cmd="mariadb_initdb"
start_precmd="mariadb_prestart"
pidfile="@VARBASE@/run/mariadb/mariadb.pid"

mariadb_initdb() {
        if [ -f @MARIADB_DATADIR@/mysql/user.frm ]; then
                echo "The MariaDB database has already been initialized."
                echo "Skipping database initialization."
        else
		echo "Initializing MariaDB database system tables."
		sh @PREFIX@/bin/mysql_install_db --force \
			--user=@MARIADB_USER@ \
			--datadir=@MARIADB_DATADIR@
		if [ -d @MARIADB_DATADIR@ ]; then
			/usr/sbin/chown -R @MARIADB_USER@:@MARIADB_GROUP@ \
				@MARIADB_DATADIR@
                fi
	fi
}

mariadb_prestart() {
	if ! [ -f @MARIADB_DATADIR@/mysql/user.frm ]; then
		mariadb_initdb
	fi
	rundir=$(dirname "${pidfile}")
	if ! [ -d "${rundir}" ]; then
		mkdir -p "${rundir}"
		chown @MARIADB_USER@:@MARIADB_GROUP@ "${rundir}"
	fi
	ulimit -n 4096
}

load_rc_config $name
run_rc_command "$1"
