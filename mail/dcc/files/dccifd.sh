#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dccifd.sh,v 1.2 2015/06/05 13:43:20 gdt Exp $
#
#
# PROVIDE: dccifd
# REQUIRE: DAEMON
# BEFORE:  mail spamd
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name=dccifd
rcvar=$name
start_precmd=dcc_precmd
start_cmd="@DCC_RC@ \${rc_flags:+-x} -m $name start"
stop_cmd="@DCC_RC@ \${rc_flags:+-x} -m $name stop"

dcc_precmd ()
{
	if [ ! -s @DCC_HOME@/ids ]; then
		@DCC_FIXMAP@ \
			-i @DCC_HOME@/ids \
			-I @DCC_EGDIR@/ids \
			-m @DCC_HOME@/map \
			-t @DCC_HOME@/map.txt \
			-T @DCC_EGDIR@/map.txt
	fi
}

load_rc_config $name
run_rc_command "${1}"
