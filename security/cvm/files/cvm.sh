#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cvm.sh,v 1.3 2017/07/31 20:34:17 schmonz Exp $
#

# PROVIDE: cvm
# REQUIRE: LOGIN

name="cvm"

# User-settable rc.conf variables and their default values:
: ${cvm_postenv:="CVM_LOOKUP_SECRET=''"}
: ${cvm_datalimit:="180000000"}
: ${cvm_module:="qmail"}
: ${cvm_protocol:="local"}
: ${cvm_log:="YES"}
: ${cvm_logcmd:="logger -t nb${name} -p auth.info"}
: ${cvm_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
command="@PREFIX@/bin/cvm-${cvm_module}"
start_precmd="cvm_precmd"

cvm_precmd()
{
	if [ -f /etc/rc.subr ] && ! checkyesno cvm_log; then
		cvm_logcmd=${cvm_nologcmd}
	fi
	umask 0
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${cvm_postenv}
@PREFIX@/bin/softlimit -m ${cvm_datalimit} @PREFIX@/bin/cvm-${cvm_module}
cvm-${cvm_protocol}:@VARBASE@/run/cvm-${cvm_module}
2>&1 |
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid cvmlog ${cvm_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	cvm_precmd
	eval ${command} ${cvm_flags} ${command_args}
fi
