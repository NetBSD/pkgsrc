#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sshd.sh,v 1.15 2015/01/17 01:11:06 gdt Exp $
#
# PROVIDE: sshd
# REQUIRE: DAEMON LOGIN

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="sshd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
keygen_command="@PREFIX@/bin/ssh-keygen"
pidfile="@SSH_PID_DIR@/${name}.pid"
required_files="@PKG_SYSCONFDIR@/sshd_config"
extra_commands="keygen reload"

sshd_keygen()
{
	(
	umask 022
	if [ -f @PKG_SYSCONFDIR@/ssh_host_key ]; then
		@ECHO@ "You already have an RSA host key in @PKG_SYSCONFDIR@/ssh_host_key"
		@ECHO@ "Skipping protocol version 1 RSA Key Generation"
	else
		${keygen_command} -t rsa1 -b 1024 -f @PKG_SYSCONFDIR@/ssh_host_key -N ''
	fi

	if [ -f @PKG_SYSCONFDIR@/ssh_host_dsa_key ]; then
		@ECHO@ "You already have a DSA host key in @PKG_SYSCONFDIR@/ssh_host_dsa_key"
		@ECHO@ "Skipping protocol version 2 DSA Key Generation"
	else
		${keygen_command} -t dsa -f @PKG_SYSCONFDIR@/ssh_host_dsa_key -N ''
	fi

	if [ -f @PKG_SYSCONFDIR@/ssh_host_rsa_key ]; then
		@ECHO@ "You already have a RSA host key in @PKG_SYSCONFDIR@/ssh_host_rsa_key"
		@ECHO@ "Skipping protocol version 2 RSA Key Generation"
	else
		${keygen_command} -t rsa -f @PKG_SYSCONFDIR@/ssh_host_rsa_key -N ''
	fi
# HAVE_ECDSA_START
	if [ -f @PKG_SYSCONFDIR@/ssh_host_ecdsa_key ]; then
		@ECHO@ "You already have a ECDSA host key in @PKG_SYSCONFDIR@/ssh_host_ecdsa_key"
		@ECHO@ "Skipping protocol version 2 ECDSA Key Generation"
	else
		${keygen_command} -t ecdsa -f @PKG_SYSCONFDIR@/ssh_host_ecdsa_key -N ''
	fi
# HAVE_ECDSA_STOP
# HAVE_ED25519_START
	if [ -f @PKG_SYSCONFDIR@/ssh_host_ed25519_key ]; then
		@ECHO@ "You already have a ED25519 host key in @PKG_SYSCONFDIR@/ssh_host_ed25519_key"
		@ECHO@ "Skipping protocol version 2 ED25519 Key Generation"
	else
		${keygen_command} -t ed25519 -f @PKG_SYSCONFDIR@/ssh_host_ed25519_key -N ''
	fi
# HAVE_ED25519_STOP
	)
}

sshd_precmd()
{
	if [ ! -f @PKG_SYSCONFDIR@/ssh_host_key -o \
	     ! -f @PKG_SYSCONFDIR@/ssh_host_dsa_key -o \
	     ! -f @PKG_SYSCONFDIR@/ssh_host_rsa_key -o \
	     ! -f @PKG_SYSCONFDIR@/ssh_host_ecdsa_key -o \
	     ! -f @PKG_SYSCONFDIR@/ssh_host_ed25519_key ]; then
		if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]
		then
			run_rc_command keygen
		else
			eval ${keygen_cmd}
		fi
	fi
}

keygen_cmd=sshd_keygen
start_precmd=sshd_precmd

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]
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
