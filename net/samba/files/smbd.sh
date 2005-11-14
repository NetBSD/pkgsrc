#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smbd.sh,v 1.11 2005/11/14 08:05:27 jlam Exp $
#
# PROVIDE: smbd
# REQUIRE: nmbd

. /etc/rc.subr

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_vars="nmbd"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

load_rc_config $name
load_rc_config_var nmbd nmbd
run_rc_command "$1"
