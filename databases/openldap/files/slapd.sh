#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: slapd.sh,v 1.5 2004/02/14 11:31:50 jlam Exp $
#
# OpenLDAP standalone LDAP daemon
#
# PROVIDE: slapd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="slapd"
rcvar=${name}
command="@PREFIX@/libexec/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	eval [ -z "\$${rcvar}" ] && eval ${rcvar}=NO
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${slapd_flags} ${command_args}
fi
