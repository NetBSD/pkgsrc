#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ssh2_secure_shell.sh,v 1.2 2002/09/20 02:02:00 grant Exp $
#
# PROVIDE: ssh2_secure_shell
# REQUIRE: DAEMON LOGIN

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="ssh2_secure_shell"
rcvar=$name
command="@PREFIX@/sbin/sshd2"
keygen_command="@PREFIX@/bin/ssh-keygen2"
pidfile="@SSH_PID_DIR@/sshd2_22.pid"
required_files="@PKG_SYSCONFDIR@/sshd2_config"
extra_commands="keygen reload"

ssh2_secure_shell_keygen()
{
	(
	umask 022
	if [ -f @PKG_SYSCONFDIR@/hostkey ]; then
		@ECHO@ "You already have an DSA host key in @PKG_SYSCONFDIR@/hostkey"
		@ECHO@ "Skipping Key Generation"
	else
		${keygen_command} -P -b 1024 -t dsa -c "1024-bit dsa hostkey" @PKG_SYSCONFDIR@/hostkey
	fi
	)
}

ssh2_secure_shell_precmd()
{
	if [ ! -f @PKG_SYSCONFDIR@/hostkey ]; then
		$0 keygen
	fi
}

keygen_cmd=ssh2_secure_shell_keygen
start_precmd=ssh2_secure_shell_precmd

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		if [ -x ${command} -a -f ${required_files} ]
		then
			@ECHO@ "Starting ${name}."
			eval ${start_precmd}
			eval ${command} ${sshd_flags} ${command_args}
		fi
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "Stopping ${name}."
			kill -TERM ${pid}
		else
			@ECHO@ "${name} not running?"
		fi
		;;
	restart)
		( $0 stop )
		sleep 1
		$0 start
		;;
	status)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "${name} is running as pid ${pid}."
		else
			@ECHO@ "${name} is not running."
		fi
		;;
	keygen)
		eval ${keygen_cmd}
		;;
	esac
fi
