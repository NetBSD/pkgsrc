#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: syslogng.sh,v 1.1.1.1 2006/05/14 19:56:05 adrianp Exp $
#

# PROVIDE: syslogd
# REQUIRE: mountcritremote sysdb wscons
# BEFORE:  SERVERS

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="syslogng"
rcvar=${name}
ngname="syslog-ng"
command="@PREFIX@/sbin/${ngname}"
pidfile="@VARBASE@/run/${ngname}.pid"
required_files="@PKG_SYSCONFDIR@/${ngname}.conf"
extra_commands="reload checkconfig"
reload_cmd="syslogng_reload"
checkconfig_cmd="syslogng_checkconfig"
command_args="-p ${pidfile} -f ${required_files}"

syslogng_reload() {
	kill -HUP `cat ${pidfile}`
}

syslogng_checkconfig() {
	${command} -s -f ${required_files}
}

load_rc_config $name
run_rc_command "$1"
