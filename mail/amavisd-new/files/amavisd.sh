#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: amavisd.sh,v 1.3 2010/12/24 07:19:35 kefren Exp $
#
# PROVIDE: amavisd
# REQUIRE: DAEMON
# BEFORE:  mail
#
#
# You will need to set some variables in /etc/rc.conf to start amavisd:
#
# amavisd=YES
#
# The following variables are optional:
#
#	amavisd_user="@AMAVIS_USER@"	# user to run amavisd as
#	amavisd_group="@AMAVIS_GROUP@"	# ${amavisd_user}'s group
#	amavisd_dirs="@AMAVIS_DIR@"	# directories that should be created
#					# before starting amavisd

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="amavisd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_interpreter="@PERL5@"
pidfile="@AMAVIS_DIR@/amavisd.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
: ${amavisd_user="@AMAVIS_USER@"}
: ${amavisd_group="@AMAVIS_GROUP@"}
: ${amavisd_dirs="@AMAVIS_DIR@ @AMAVIS_DIR@/db @AMAVIS_DIR@/tmp @AMAVIS_QUARANTINE@"}

start_precmd="amavisd_prestart"
stop_cmd="amavisd_stop"

amavisd_prestart()
{
	@RM@ -f @AMAVIS_DIR@/amavisd.sock
	for dir in ${amavisd_dirs}; do
		@MKDIR@ $dir
		@CHOWN@ ${amavisd_user}:${amavisd_group} $dir
		@CHMOD@ 0750 $dir
	done
}

# Net::Server breaks rc.subr's techniques for detecting whether the
# process running at a certain PID is actually the process we wish to
# stop.  Just unconditionally send SIGTERM to the PID instead.
#
amavisd_stop()
{
	@ECHO@ "Stopping ${name}."
	if [ -f ${pidfile} ]; then
		pid=`@HEAD@ -1 ${pidfile}`
		doit="@SU@ -m ${amavisd_user} -c \"kill ${pid}\""
		if ! eval $doit && [ -z "$rc_force" ]; then
			return 1
		fi
		wait_for_pids $pid
	fi
	@RM@ -f ${pidfile}
	for dir in ${amavisd_dirs}; do
		@RMDIR@ -p $dir 2>/dev/null || @TRUE@
	done
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}          
	${command} ${amavisd_flags} ${command_args}
fi
