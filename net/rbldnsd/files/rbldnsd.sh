#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rbldnsd.sh,v 1.1.1.1 2006/12/08 22:14:12 cube Exp $
#

# PROVIDE: rbldnsd
# REQUIRE: SERVERS
# BEFORE:  DAEMON
# KEYWORD: chrootdir

. /etc/rc.subr

name="rbldnsd"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
start_precmd="rbldnsd_precmd"
extra_commands="reload"
required_dirs="$rbldnsd_chrootdir"

rbldnsd_precmd()
{
	if [ -z "$rbldnsd_zones" ]; then
		echo "rbldnsd_zones must be set."
		return 1
	fi

	command_args="-p ${pidfile} ${rbldnsd_zones}"

	if [ -z "$rbldnsd_chrootdir" ]; then
		return 0;
	fi

	if [ -f /etc/localtime ]; then
		@CMP@ -s /etc/localtime "${rbldnsd_chrootdir}/etc/localtime" || \
		    @CP@ -p /etc/localtime "${rbldnsd_chrootdir}/etc/localtime"
	fi

	command_args="-u @RBLDNSD_USER@:@RBLDNSD_GROUP@ ${command_args}"
	command_args="-r ${rbldnsd_chrootdir} ${command_args}"
}

load_rc_config "$rcvar"
run_rc_command "$1"
