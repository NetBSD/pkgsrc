#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: pgbouncer.sh,v 1.2 2014/05/13 14:18:49 fhajny Exp $
#
# PROVIDE: pgbouncer
# REQUIRE: DAEMON
#

if [ -r /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="pgbouncer"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pgbouncer_conf="@PKG_SYSCONFDIR@/${name}.ini"
required_files="${pgbouncer_conf}"
command_args="-d ${pgbouncer_conf}"
extra_commands="reload"
pgsql_user="@PGUSER@"
start_cmd="pgbouncer_start"

pidfile="@VARBASE@/run/${name}/${name}.pid"
if [ -r ${pgbouncer_conf} ] ; then
	pidfile=`grep -i pidfile ${pgbouncer_conf} | cut -d= -f2`
fi

pgbouncer_start()
{
        @ECHO@ "Starting ${name}."
	piddir=`dirname ${pidfile}`
	if [ ! -d ${piddir} ] ; then
		@MKDIR@ -p ${piddir}
		@CHOWN@ ${pgsql_user} ${piddir}
	fi

        doit="@SU@ -m ${pgsql_user} -c '${command} ${command_args}'"
        eval $doit
}

load_rc_config $name
run_rc_command "$1"
