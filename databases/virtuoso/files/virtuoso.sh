#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: virtuoso.sh,v 1.1 2013/04/13 13:16:02 jaapb Exp $
#
# PROVIDE: virtuoso
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="virtuoso"
rcvar=$name
command="@PREFIX@/bin/virtuoso-t"
: ${virtuoso_user:=@VIRTUOSO_USER@}
: ${virtuoso_group:=@VIRTUOSO_GROUP@}
: ${virtuoso_config:=@PREFIX@/share/virtuoso/db/virtuoso.ini}

command_args="+config_file ${virtuoso_config} ${virtuoso_flags}"

load_rc_config $name
run_rc_command "$1"
