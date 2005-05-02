#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dirmngr.sh,v 1.1 2005/05/02 22:33:37 shannonjr Exp $
#
# PROVIDE: dirmngr
# REQUIRE: DAEMON
#

if [ -f @PKG_SYSCONFDIR@/rc.subr ]; then
	. @PKG_SYSCONFDIR@/rc.subr
fi

name="dirmngr"
rcvar="${name}"
dirmngr_user="dirmngr"
dirmngr_group="dirmngr"
dirmngr_flags="--daemon"
dirmngr_command="@PREFIX@/sbin/runDirmngr"
start_precmd="dirmngr_precmd"
start_cmd="dirmngr_start"
start_postcmd="dirmngr_postcmd"
stop_cmd="dirmngr_stop"
required_dirs="@PKG_SYSCONFDIR@/dirmngr"
required_files="@PKG_SYSCONFDIR@/dirmngr/ldapservers.conf"

dirmngr_precmd()
{
	mkdir -p @VARBASE@/run/dirmngr
	chgrp dirmngr @VARBASE@/run/dirmngr
	chmod 775 @VARBASE@/run/dirmngr
	mkdir -p /tmp/dirmngr
	chgrp dirmngr /tmp/dirmngr
	chmod 755 /tmp/dirmngr
}

dirmngr_start()
{
       for _f in $required_dirs; do
		if [ ! -d "${_f}/." ]; then
			warn "${_f} is not a directory."
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	for _f in $required_files; do
		if [ ! -r "${_f}" ]; then
			warn "${_f} is not readable."
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	eval `${dirmngr_command} ${rc_flags}`
}

dirmngr_postcmd()
{
	echo ${DIRMNGR_INFO} >/tmp/dirmngr/dirmngr.info
	chmod 644 /tmp/dirmngr/dirmngr.info
	dirmngr_pid=`cut -f 2 -d ':' /tmp/dirmngr/dirmngr.info`
}

dirmngr_stop()
{
	if [ -f /tmp/dirmngr/dirmngr.info ] ; then
		kill `cut -f 2 -d ':' /tmp/dirmngr/dirmngr.info`
	fi
}

load_rc_config $name
run_rc_command "$1"
