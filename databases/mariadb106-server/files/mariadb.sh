#!/bin/sh
#
# $NetBSD: mariadb.sh,v 1.3 2022/02/06 17:52:25 abs Exp $
#
# PROVIDE: mariadb mysqld
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#
# Optional rc.conf variables:
#	mariadb_flags=""		   # additional mariadb startup flags
#	mariadb_datadir="/path/to/datadir" # path to mariadb datadir

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="mariadb"
rcvar=${name}

load_rc_config $name
: ${mariadb_datadir:=@MARIADB_DATADIR@}

procname="@PREFIX@/sbin/mariadbd"
command="@PREFIX@/bin/mariadbd-safe"
command_args="--pid-file=@VARBASE@/run/mariadb/mariadb.pid"
command_args="${command_args} --user=@MARIADB_USER@"
command_args="${command_args} --datadir=$mariadb_datadir"
command_args="${command_args} --log-error=@VARBASE@/log/mariadb/error.log"
command_args="${command_args} ${mariadb_flags} &"
extra_commands="initdb"
initdb_cmd="mariadb_initdb"
start_precmd="mariadb_prestart"
pidfile="@VARBASE@/run/mariadb/mariadb.pid"

mariadb_initdb() {
        if [ -f $mariadb_datadir/mysql/user.frm ]; then
                echo "The MariaDB database has already been initialized."
                echo "Skipping database initialization."
        else
		echo "Initializing MariaDB database system tables."
		sh @PREFIX@/bin/mysql_install_db --force \
			--user=@MARIADB_USER@ \
			--datadir=$mariadb_datadir
		if [ -d $mariadb_datadir ]; then
			/usr/sbin/chown -R @MARIADB_USER@:@MARIADB_GROUP@ \
				$mariadb_datadir
                fi
	fi
}

mariadb_prestart() {
	if ! [ -f $mariadb_datadir/mysql/user.frm ]; then
		mariadb_initdb
	fi
	rundir=$(dirname "${pidfile}")
	if ! [ -d "${rundir}" ]; then
		mkdir -p "${rundir}"
		chown @MARIADB_USER@:@MARIADB_GROUP@ "${rundir}"
	fi
	ulimit -n 4096
}

run_rc_command "$1"
