#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spamass-milter.sh,v 1.4 2005/08/24 16:08:13 tv Exp $
#

# PROVIDE: spamass-milter
# REQUIRE: spamd
# KEYWORD: shutdown
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="spamass_milter"
rcvar=${name}
command="@PREFIX@/sbin/spamass-milter"
command_args="-u nobody -p /var/run/spamass.sock -f"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name

	# hack: put ${spamass_milter_flags} last in args,
	# so that "-- ..." spamc flags can be added to the end
	#
	command_args="${command_args} ${spamass_milter_flags}"
	spamass_milter_flags=

	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args} ${spamass_milter_flags}
fi
