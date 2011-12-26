# $NetBSD: mpdas.sh,v 1.2 2011/12/26 13:22:28 joerg Exp $
#
# PROVIDE: mpdas
# # REQUIRE: DAEMON network
# KEYWORD: shutdown

. /etc/rc.subr

name="mpdas"
rcvar=$name
command="@PREFIX@/bin/mpdas"
command_args="-d"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n "${name}"
        ${command} ${command_args}
fi
