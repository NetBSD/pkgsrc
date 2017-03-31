#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dnsdist.sh,v 1.1 2017/03/31 20:49:51 fhajny Exp $
#
# PROVIDE: dnsdist 
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dnsdist"
rcvar=$name
command="@PREFIX@/bin/dnsdist"
dnsdist_flags="${dnsdist_flags:- -d -u @DNSDIST_USER@ -g @DNSDIST@ -C @PKG_SYSCONFDIR@/dnsdist.conf}"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${dnsdist_flags}
fi
