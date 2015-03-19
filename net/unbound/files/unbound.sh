#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unbound.sh,v 1.4 2015/03/19 22:37:06 pettai Exp $
#
# PROVIDE: unbound
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="unbound"
rcvar=${name}

command=@PREFIX@/sbin/${name}
pidfile=/var/run/${name}/${name}.pid
required_files="@PKG_SYSCONFDIR@/unbound.conf"
extra_commands="reload"
start_precmd="unbound_precmd"

unbound_precmd()
{
	if [ ! -d @VARBASE@/run/unbound ]; then
		@MKDIR@ @VARBASE@/run/unbound
		@CHMOD@ 0750 @VARBASE@/run/unbound
		@CHOWN@ @UNBOUND_USER@:@UNBOUND_GROUP@ @VARBASE@/run/unbound
	fi
}

unbound_flags=${unbound_flags:-""}

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${nsd_flags}
fi
