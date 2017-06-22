#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cups-browsed.sh,v 1.1 2017/06/22 12:30:25 wiz Exp $
#
# PROVIDE: cups-browsed
# REQUIRE: cups

. /etc/rc.subr

# The program's name is "cups-browsed", but shell varnames can't contain hyphens
# Also, the program itself doesn't daemonize, use a shell wrapper

name="cups_browsed" # Prefix for various ${name}_XXX variables
cups_browsed_rcname="cups-browsed" # File name in rc.conf.d
rcvar="cups_browsed" # Name of YES/NO rc variable
command=@PREFIX@/libexec/cups-browsed # Daemonizing wrapper
procname="@PREFIX@/sbin/cups-browsed" # Real command that appears in ps(1) output
conf_file="@PKG_SYSCONFDIR@/cups/cups-browsed.conf"
required_files="${conf_file}"
pidfile=@VARBASE@/run/cups-browsed.pid
stop_postcmd=cups_browsed_remove_pidfile

cups_browsed_remove_pidfile() {
	rm -f "${pidfile}"
}

load_rc_config $cups_browsed_rcname
run_rc_command $1
