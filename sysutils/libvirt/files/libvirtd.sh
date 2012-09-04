# $NetBSD
#
# PROVIDE: libvirtd
# # REQUIRE: DAEMON network
# KEYWORD: shutdown

. /etc/rc.subr

name="libvirtd"
rcvar=$name
command="@PREFIX@/sbin/libvirtd"
command_args="-d"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        echo -n "${name}"
        ${command} ${command_args}
fi
