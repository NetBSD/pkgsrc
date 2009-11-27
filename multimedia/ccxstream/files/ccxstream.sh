#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ccxstream.sh,v 1.1.1.1 2009/11/27 08:38:49 wiz Exp $
#
# PROVIDE: ccxstream
# REQUIRE: DAEMON network
# KEYWORD: shutdown

. /etc/rc.subr

name="ccxstream"
rcvar=$name
command="@PREFIX@/bin/ccxstream"
command_args="-r - -f"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n "${name}"
        ${command} ${ccxstream_flags} ${command_args}
fi
