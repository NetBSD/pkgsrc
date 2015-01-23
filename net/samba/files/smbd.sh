#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smbd.sh,v 1.14 2015/01/23 08:09:37 obache Exp $
#
# PROVIDE: smbd

. /etc/rc.subr

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@SAMBA_PIDDIR@/${name}.pid"
required_files="@SAMBA_ETCDIR@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}

# load_rc_config_var() from /etc/rc.subr on the netbsd-3 branch, for
# the benefit of platforms with older versions of /etc/rc.subr.
#
load_rc_config_var()
{
	eval $(eval '(
		load_rc_config '$1' >/dev/null;
		if [ -n "${'$2'}" -o "${'$2'-UNSET}" != "UNSET" ]; then
			echo '$2'=\'\''${'$2'}\'\'';
		fi
	)' )
}

load_rc_config $name
load_rc_config_var nmbd nmbd
run_rc_command "$1"
