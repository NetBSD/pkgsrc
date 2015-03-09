#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nsd.sh,v 1.4 2015/03/09 11:34:26 pettai Exp $
#
# PROVIDE: nsd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="nsd"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}/${name}.pid
required_files="@PKG_SYSCONFDIR@/nsd.conf"
start_precmd="nsd_precmd"

nsd_precmd()
{
	if [ ! -d @VARBASE@/run/nsd ]; then
		@MKDIR@ @VARBASE@/run/nsd
		@CHMOD@ 0750 @VARBASE@/run/nsd
		@CHOWN@ @NSD_USER@:@NSD_GROUP@ @VARBASE@/run/nsd
	fi
}

nsd_flags=${nsd_flags:-""}

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${nsd_flags}
fi
