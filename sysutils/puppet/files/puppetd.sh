#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: puppetd.sh,v 1.1.1.1 2008/03/13 14:17:05 tonnerre Exp $
#
# PROVIDE: puppetd
# REQUIRE: DAEMON
# KEYWORD: shutdown

# Add the following lines to /etc/rc.conf to enable puppetd:
#
# puppetd="YES"
# puppetd_confdir="@PREFIX@/etc/puppet"
# puppetd_pid="/var/run/${name}.pid"
# puppetd_flags="--confdir $puppetd_confdir --rundir /var/run"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="puppetd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@PREFIX@/bin/ruby18"
: ${puppetd_confdir="@PREFIX@/etc/puppet"}
: ${puppetd_pid="/var/run/${name}.pid"}
: ${puppetd_flags="--confdir $puppetd_confdir --rundir /var/run"}

pidfile="$puppetd_pid"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

run_rc_command "$1"
