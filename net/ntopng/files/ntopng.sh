#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ntopng.sh,v 1.1 2016/04/08 16:59:07 adam Exp $
#
# PROVIDE: ntopng
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ntopng"
rcvar=$name
# XXX must be in tmp, because ntopng runs as nobody
pidfile="@VARBASE@/tmp/$name.pid"
command="@PREFIX@/bin/$name"
command_args="-e -G $pidfile"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -c "${command}"
fi
