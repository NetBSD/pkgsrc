#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upclient.sh,v 1.7 2003/07/30 17:56:43 jmmv Exp $
#
# PROVIDE: upclient
# REQUIRE: NETWORK
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upclient"
rcvar="${name}"
command="@PREFIX@/bin/upclient"
upclient_user="nobody"

if [ -f /etc/rc.subr ]; then
	load_rc_config "$name"
	run_rc_command "$1"
else
	printf ' upclient'
	${command} ${upclient_flags} ${command_args}
fi
