#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nmbd.sh,v 1.1 2015/05/12 12:19:52 ryoon Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

. /etc/rc.subr

name="nmbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@SMB_PID@/${name}.pid"
required_files="@SMB_CONFIG@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

reload_cmd=":"			# avoid dumping debug output on SIGHUP

load_rc_config $name
run_rc_command "$1"
