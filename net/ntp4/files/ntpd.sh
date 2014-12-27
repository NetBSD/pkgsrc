#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ntpd.sh,v 1.4 2014/12/27 02:48:27 taca Exp $
#

# PROVIDE: ntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN
# KEYWORD: chrootdir

. /etc/rc.subr

name="ntpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
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

	if [ ! -d "${ntpd_chrootdir}/etc" ]; then
		mkdir "${ntpd_chrootdir}/etc"
	fi
	if [ ! -f "${ntpd_chrootdir}/etc/services" ]; then
		(echo "ntp		123/udp"
		 echo "ntp		123/tcp") \
			> "${ntpd_chrootdir}/etc/services"
	fi
	if [ ! -d "${ntpd_chrootdir}/var/db" ]; then
		mkdir -p "${ntpd_chrootdir}/var/db"
	fi
	if [ ! -f "${ntpd_chrootdir}/var/db/services.cdb" ]; then
		services_mkdb -o "${ntpd_chrootdir}/var/db/services.cdb" \
			"${ntpd_chrootdir}/etc/services"
	fi

	#	Change run_rc_commands()'s internal copy of $ntpd_flags
	#
	rc_flags="-u ntpd:ntpd -i ${ntpd_chrootdir} $rc_flags"
}

load_rc_config $name
run_rc_command "$1"
