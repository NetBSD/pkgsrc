#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: puppetmasterd.sh,v 1.1.1.1 2008/03/13 14:17:05 tonnerre Exp $
#
# PROVIDE: puppetmasterd
# REQUIRE: DAEMON
# KEYWORD: shutdown

# Add the following lines to /etc/rc.conf to enable puppetmasterd:
#
# puppetmasterd="YES"
# puppetmasterd_confdir:	Set to @PREFIX@/etc/puppet by default
# puppetmasterd_flags:		Set to --confdir $puppetmasterd_confdir --rundir /var/run" by default
#

if [ -f /etc/rc.subr ]; then
	$_rc_subr_loaded . /etc/rc.subr
fi

name="puppetmasterd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_interpreter="@PREFIX@/bin/ruby18"
start_precmd="puppetmasterd_checkconfig"
restart_precmd="puppetmasterd_checkconfig"
: ${puppetmasterd_confdir="@PREFIX@/etc/puppet"}
: ${puppetmasterd_pid="/var/run/${name}.pid"}
: ${puppetmasterd_flags="--confdir $puppetmasterd_confdir --rundir /var/run"}

pidfile="$puppetmasterd_pid"

puppetmasterd_checkconfig() {
	echo -n "Performing sanity check of ${name} configuration: "
	${command} --parseonly ${puppetmasterd_flags} >/dev/null 2>&1
	rv=$?
	if [ $rv != 0 ]; then
		echo "FAILED, ${name} exited with status ${rv}"
		${command} --parseonly ${puppetmasterd_flags}
		return 1
	else
		echo "OK"
	fi
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config "$name"
elif [ -f /etc/rc.conf ]; then
	. /etc/rc.conf
fi

run_rc_command "$1"
