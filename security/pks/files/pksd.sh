#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pksd.sh,v 1.8 2005/10/23 17:45:39 adrianp Exp $
#
# PROVIDE: pksd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="pksd"
rcvar=${name}

command="@PREFIX@/bin/pksd"
run_command="@PREFIX@/bin/pks-queue-run.sh"
ctl_command="@PREFIX@/bin/pksdctl"
client_command="@PREFIX@/bin/pksclient"

conf_file="@PKG_SYSCONFDIR@/${name}.conf"
required_files="${conf_file}"
extra_commands="dbinit"
pksd_user="@PKS_USER@"
pksd_group="@PKS_GROUP@"

pksd_dbinit()
{
	(
	umask 007
	if [ -r ${conf_file} ]
	then
		dbdir=`@AWK@ '/db_dir/ { print $2 }' < ${conf_file}`
		if [ ! -f ${dbdir}/keydb000 -a -x ${client_command} ]
		then
			@SU@ -m ${pksd_user} -c "${client_command} ${dbdir} create"
		fi
	fi
	)
}

pksd_start()
{
	if [ -r ${conf_file} -a -x ${command} -a -x ${run_command} ]
	then
		@ECHO@ "Starting ${name} (local)."
		@ECHO@ "${command} ${conf_file}"
		@SU@ -m ${pksd_user} -c "${command} ${conf_file} &"
		sleep 5
		@SU@ -m ${pksd_user} -c "${run_command} ${conf_file}"
	fi
}

pksd_stop()
{
	if [ -r ${conf_file} -a -x ${ctl_command} ]
	then
		socket=`@AWK@ '/socket_name/ { print $2 }' < ${conf_file}`
		if [ -S ${socket} ]
		then
			@ECHO@ "Stopping ${name} (local)."
			@SU@ -m ${pksd_user} -c "${ctl_command} ${socket} shutdown"
		fi
	fi
} 

dbinit_cmd=pksd_dbinit
start_precmd=pksd_dbinit
start_cmd=pksd_start
stop_cmd=pksd_stop

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	pksd_dbinit
	pksd_start
fi
