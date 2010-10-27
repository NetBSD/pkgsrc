#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dccd.sh,v 1.1.1.1 2010/10/27 12:26:37 gdt Exp $
#
#
# PROVIDE: dccd
# REQUIRE: DAEMON
# BEFORE:  mail spamd

$_rc_subr_loaded . /etc/rc.subr

name="dccd"
rcvar="${name}"
start_precmd="dcc_precmd"
command="@PREFIX@/libexec/start-${name}"
procname="@PREFIX@/libexec/${name}"
pidfile="@DCC_RUN@/${name}.pid"
#
#
#	start-dcc{d,ifd,m} understands certain flags while
#	it passes everything behind -a to dcc{d,ifd,m}
#
#
dcc_precmd()
{
	if [ -n "${rc_flags}" ]; then
		rc_flags="-a '${rc_flags}'"
	fi

	eval dcc_start_flags=\$${name}_start_flags
	if [ -n "${dcc_start_flags}" ]; then
		rc_flags="${dcc_start_flags} ${rc_flags}"
	fi

	if [ -n "${command_args}" ]; then
		rc_flags="${command_args} ${rc_flags}"
		unset command_args
	fi
}

load_rc_config "${name}"
run_rc_command "${1}"
