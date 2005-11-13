#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ircd-hybrid.sh,v 1.3 2005/11/13 22:40:00 adrianp Exp $
#
# PROVIDE: ircdhybrid
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ircdhybrid"
rcvar=$name
pidfile="@VARBASE@/run/ircd-hybrid/ircd.pid"
command="@PREFIX@/bin/ircd"
conffile="@PKG_SYSCONFDIR@/ircd.conf"
required_files="$conffile"
ircdhybrid_user="@IRCD_HYBRID_IRC_USER@"
ircdhybrid_group="@IRCD_HYBRID_IRC_GROUP@"
start_precmd="set_pid_file"

set_pid_file () {
	@TOUCH@ $pidfile 
	@CHOWN@ @IRCD_HYBRID_IRC_USER@ $pidfile 
	@CHGRP@ @IRCD_HYBRID_IRC_GROUP@ $pidfile
	@CHMOD@ 0640 $pidfile
}

load_rc_config $name
run_rc_command "$1"
