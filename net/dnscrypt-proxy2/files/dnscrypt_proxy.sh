#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnscrypt_proxy.sh,v 1.1 2018/10/01 15:05:48 nia Exp $
#
# PROVIDE: dnscrypt_proxy
# REQUIRE: DAEMON

. /etc/rc.subr

name="dnscrypt_proxy"
rcvar=${name}
command="@PREFIX@/bin/dnscrypt-proxy"
command_args="-syslog -config @PKG_SYSCONFDIR@/${name}.toml -pidfile @VARBASE@/run/${name}.pid &"
required_files="@PKG_SYSCONFDIR@/${name}.toml"
pidfile="@VARBASE@/run/${name}.pid"
extra_commands="configtest"
configtest_cmd="dnscrypt_proxy_configtest"

dnscrypt_proxy_configtest()
{
	if [ ! -f ${required_files} ]; then
		warn "${required_files} does not exist."
		return 1;
	fi
	${command} -check -config ${required_files}
}

load_rc_config $name
run_rc_command "$1"
