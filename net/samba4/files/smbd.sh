#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smbd.sh,v 1.3 2026/03/02 10:07:44 adam Exp $
#
# PROVIDE: smbd

. /etc/rc.subr

name="smbd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@SMB_PID@/${name}.pid"
required_files="@SMB_CONFIG@/smb.conf"
extra_commands="reload"
command_args="-D"		# _must_ start as daemon from rc.d;
				# add more flags through ${${name}_flags}
start_precmd="smbd_precmd"

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

smbd_precmd()
{
	if ! [ -f /proc/cpuinfo ]; then
		echo "WARNING: Samba requires a Linux-compatible procfs!"
		echo "WARNING: Please mount /proc before starting Samba."
	fi
}


load_rc_config $name
run_rc_command "$1"
