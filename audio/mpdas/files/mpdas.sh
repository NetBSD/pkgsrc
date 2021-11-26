# $NetBSD: mpdas.sh,v 1.3 2021/11/26 15:23:05 pho Exp $
#
# PROVIDE: mpdas
# REQUIRE: mpd
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
