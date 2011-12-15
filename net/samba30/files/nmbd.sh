#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nmbd.sh,v 1.1.1.1 2011/12/15 22:23:24 asau Exp $
#
# PROVIDE: nmbd
# REQUIRE: DAEMON

. /etc/rc.subr

name="nmbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

reload_cmd=":"			# avoid dumping debug output on SIGHUP

load_rc_config $name
run_rc_command "$1"
