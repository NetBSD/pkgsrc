#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: opensmtpd.sh,v 1.4 2024/03/02 17:01:12 vins Exp $
#

# PROVIDE: smtpd mail
# REQUIRE: LOGIN
# KEYWORD: shutdown
#       we make mail start late, so that things like .forward's are not
#       processed until the system is fully operational

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="smtpd"
rcvar=opensmtpd

: ${smtpd_config:="@PKG_SYSCONFDIR@/smtpd/${name}.conf"}
: ${smtpd_server:="@PREFIX@/sbin/${name}"}
: ${smtpd_flags:=""}

command="${smtpd_server}"
command_args="-f ${smtpd_config} -v"
required_files="${smtpd_config}"
pidfile="@VARBASE@/run/${name}.pid"

start_precmd="smtpd_precmd"
check_cmd="smtpd_check"
extra_commands="check"

smtpd_check()
{
	echo "Performing sanity check on smtpd configuration:"
	eval ${command} ${command_args} ${smtpd_flags} -n
}

smtpd_precmd()
{
	smtpd_check
}

load_rc_config $name
run_rc_command "$1"
