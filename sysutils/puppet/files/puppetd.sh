#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: puppetd.sh,v 1.2 2008/04/04 15:20:48 jlam Exp $
#
# PROVIDE: puppetd
# REQUIRE: DAEMON
# KEYWORD: shutdown

# Add the following lines to /etc/rc.conf to enable puppetd:
#
# puppetd="YES"
# puppetd_confdir="@PKG_SYSCONFDIR@"
# puppetd_pid="/var/run/${name}.pid"
# puppetd_flags="--confdir $puppetd_confdir --rundir /var/run"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="puppetd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@RUBY@"
: ${puppetd_confdir="@PKG_SYSCONFDIR@"}
: ${puppetd_pid="/var/run/${name}.pid"}
: ${puppetd_flags="--confdir $puppetd_confdir --rundir /var/run"}

pidfile="$puppetd_pid"

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

run_rc_command "$1"
