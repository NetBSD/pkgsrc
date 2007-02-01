#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ircd-hybrid.sh,v 1.4 2007/02/01 23:19:56 wiz Exp $
#
# PROVIDE: ircdhybrid
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ircdhybrid"
rcvar=$name
piddir="@VARBASE@/run/ircd-hybrid"
pidfile="$piddir/ircd.pid"
command="@PREFIX@/bin/ircd"
conffile="@PKG_SYSCONFDIR@/ircd.conf"
required_files="$conffile"
ircdhybrid_user="@IRCD_HYBRID_IRC_USER@"
ircdhybrid_group="@IRCD_HYBRID_IRC_GROUP@"
start_precmd="set_pid_file"

set_pid_file () {
	@MKDIR@ $piddir
	@CHOWN@ @IRCD_HYBRID_IRC_USER@ $piddir 
	@CHGRP@ @IRCD_HYBRID_IRC_GROUP@ $piddir
	@CHMOD@ 0770 $piddir
	@TOUCH@ $pidfile 
	@CHOWN@ @IRCD_HYBRID_IRC_USER@ $pidfile 
	@CHGRP@ @IRCD_HYBRID_IRC_GROUP@ $pidfile
	@CHMOD@ 0640 $pidfile
}

load_rc_config $name
run_rc_command "$1"
