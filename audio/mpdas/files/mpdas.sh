# $NetBSD: mpdas.sh
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
