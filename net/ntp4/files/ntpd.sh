#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ntpd.sh,v 1.2 2004/03/28 06:35:03 xtraeme Exp $
#

# PROVIDE: ntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN
# KEYWORD: chrootdir

. /etc/rc.subr

name="ntpd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
start_precmd="ntpd_precmd"
required_files="@PKG_SYSCONFDIR@/ntp.conf"

ntpd_precmd()
{
	if [ -z "$ntpd_chrootdir" ]; then
		return 0;
	fi

	# If running in a chroot cage, ensure that the appropriate files
	# exist inside the cage, as well as helper symlinks into the cage 
	# from outside.
	#
	# As this is called after the is_running and required_dir checks
	# are made in run_rc_command(), we can safely assume ${ntpd_chrootdir}
	# exists and ntpd isn't running at this point (unless forcestart
	# is used).
	#
	# Before enabling ntpd_chrootdir, ensure that:
	#	- The kernel has "pseudo-device clockctl" compiled in
	#	- /dev/clockctl is present
	#	- This is only for NetBSD at this time.
	#
	if [ ! -c "${ntpd_chrootdir}/dev/clockctl" ]; then
		rm -f "${ntpd_chrootdir}/dev/clockctl"
		( cd /dev ; /bin/pax -rw -pe clockctl "${ntpd_chrootdir}/dev" )
	fi
	ln -fs "${ntpd_chrootdir}/var/db/ntp.drift" /var/db/ntp.drift

	#	Change run_rc_commands()'s internal copy of $ntpd_flags
	#
	rc_flags="-u ntpd:ntpd -i ${ntpd_chrootdir} $rc_flags"
}

load_rc_config $name
run_rc_command "$1"
