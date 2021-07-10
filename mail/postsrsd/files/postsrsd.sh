#!@RCD_SCRIPTS_SHELL@
#
# PostSRSd provides the Sender Rewriting Scheme (SRS) for Postfix
#

# PROVIDE: postsrsd
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="postsrsd"

# user-settable rc.conf variables
: ${postsrsd_secret:="@PKG_SYSCONFDIR@/${name}.secret"}
: ${postsrsd_chrootdir:="@VARBASE@/chroot/postsrsd"}

rcvar=${name}
required_files="${postsrsd_secret}"
pidfile="@VARBASE@/run/${name}.pid"
command="@PREFIX@/sbin/${name}"
start_precmd="postsrsd_precmd"

postsrsd_precmd()
{
	rc_flags="-p${pidfile} -s${postsrsd_secret} -D $rc_flags"
	if [ -z "$postsrsd_chrootdir" ]; then
		return 0;
	fi

	# If running in a chroot cage, ensure that the appropriate files
	# exist inside the cage, as well as helper symlinks into the cage 
	# from outside.
	if [ ! -d "${postsrsd_chrootdir}" ]; then
		mkdir -p "${postsrsd_chrootdir}"
	fi

	#	Change run_rc_commands()'s internal copy of $ntpd_flags
	#
	rc_flags="-upostsrsd -c${postsrsd_chrootdir} $rc_flags"
}

load_rc_config $name
run_rc_command "$1"
