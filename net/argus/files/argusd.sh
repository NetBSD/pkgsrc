#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: argusd.sh,v 1.1.1.1 2004/07/07 17:22:30 xtraeme Exp $
#

# PROVIDE: argusd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="argusd"
rcvar=$name
command="@PREFIX@/sbin/argusd"
ctl_command="@PREFIX@/sbin/argusctl"
start_cmd="${command}"
stop_cmd="${ctl_command} shutdown reason=\"argusd stop\""

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	[ "$1" eq "start" ] && $start_cmd
	[ "$1" eq "stop" ] && $stop_cmd
fi
