#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: amavismilter.sh,v 1.1.1.1 2004/08/06 15:05:54 jlam Exp $
#
# PROVIDE: amavismilter
# REQUIRE: DAEMON
# BEFORE:  mail
#
# To communicate with libmilter through a UNIX domain socket (the
# socket must exist in a location that's writable by the user named
# by ${amavismilter_user}:
#
#	amavismilter_flags="-p local:/path/to/socket"
#
# To communicate with libmilter through a TCP/IP socket:
#
#	amavismilter_flags="-p inet:port@0.0.0.0"
#
# To communicate with libmilter through a TCP/IP socket restricted to a
# particular interface address:
#
#	amavismilter_flags="-p inet:port@A.B.C.D"
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="amavismilter"
rcvar=$name
command="@PREFIX@/sbin/amavis-milter"
required_vars="amavisd"
: ${amavismilter_user="@AMAVIS_USER@"}
: ${amavismilter_flags="-p local:@AMAVIS_DIR@/amavis-milter.sock"}

start_precmd="amavismilter_precmd"

# Before starting amavis-milter, remove the old milter socket if it exists.
amavismilter_precmd()
{
	set -- ${amavismilter_flags}
	case $2 in
	local:*)
		@RM@ -f "${2#local:}"
		;;
	esac
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}
	${command} ${amavismilter_flags} ${command_args}
fi
