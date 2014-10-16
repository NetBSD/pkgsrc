#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dirmngr.sh,v 1.5 2014/10/16 04:51:08 dholland Exp $
#
# PROVIDE: dirmngr
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dirmngr"
rcvar="${name}"
dirmngr_user="@DIRMNGR_USER@"
dirmngr_group="@DIRMNGR_GROUP@"
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
	rm -f @VARBASE@/run/dirmngr/socket
	chown @DIRMNGR_USER@  @VARBASE@/run/dirmngr
	chgrp @DIRMNGR_GROUP@ @VARBASE@/run/dirmngr
	chmod 1755 @VARBASE@/run/dirmngr
	mkdir -p /tmp/dirmngr
	chgrp @DIRMNGR_GROUP@ /tmp/dirmngr
	chmod 755 /tmp/dirmngr
}

dirmngr_start()
{
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
		rm -f @VARBASE@/run/dirmngr/socket
	fi
}

load_rc_config $name
run_rc_command "$1"
