#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: stud.sh,v 1.1 2013/03/16 19:41:36 jym Exp $
#

# PROVIDE: stud
# REQUIRE: LOGIN

. /etc/rc.subr

name="stud"
rcvar=$name
command="@PREFIX@/bin/stud"
command_args="--config=@PKG_SYSCONFDIR@/stud.conf"
required_files="@PKG_SYSCONFDIR@/stud.conf"
required_dirs="$stud_chrootdir"

stud_chrootdir="@STUD_HOME@"
start_precmd="stud_precmd"

stud_precmd()
{
	for i in null random urandom; do
		if [ ! -c "${stud_chrootdir}/dev/$i" ]; then
			rm -f "${stud_chrootdir}/dev/$i"
			(cd /dev &&
			    /bin/pax -rw -pe "$i" "${stud_chrootdir}/dev")
		fi
	done
}

load_rc_config $name
run_rc_command "$1"
