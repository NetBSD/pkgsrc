#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spamass-milter.sh,v 1.1 2003/09/11 18:22:41 jmmv Exp $
#

# PROVIDE: spamass-milter
# REQUIRE: spamd
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="spamass_milter"
rcvar=${name}
command="@PREFIX@/sbin/spamass-milter"
command_args="-u nobody -p /var/run/spamass.sock -f"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${spamass_milter_flags} ${command_args}
fi
