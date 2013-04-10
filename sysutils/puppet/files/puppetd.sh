#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: puppetd.sh,v 1.3 2013/04/10 21:10:55 tonnerre Exp $
#
# PROVIDE: puppetd
# REQUIRE: DAEMON
# KEYWORD: shutdown

# Add the following lines to /etc/rc.conf to enable puppetd:
#
# puppetd="YES"
# puppetd_confdir="@PKG_SYSCONFDIR@"
# puppetd_pid="/var/run/${name}.pid"
# puppetd_flags="agent --confdir $puppetd_confdir --rundir /var/run"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="puppetd"
rcvar=$name
command="@PREFIX@/bin/puppet"
command_interpreter="@RUBY@"
: ${puppetd_confdir="@PKG_SYSCONFDIR@"}
: ${puppetd_pid="/var/run/${name}.pid"}
: ${puppetd_flags="agent --confdir $puppetd_confdir --rundir /var/run"}

pidfile="$puppetd_pid"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

run_rc_command "$1"
