#!/bin/sh
#
# $NetBSD: redmine_unicorn.sh,v 1.1 2026/02/11 07:53:37 taca Exp $
#

# PROVIDE: redmine60_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="redmine60_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine60_unicorn_start"
stop_cmd="redmine60_unicorn_stop"

redmine60_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@
	@PREFIX@/bin/bundle@RUBY_SUFFIX@ exec @PREFIX@/bin/unicorn@RUBY_SUFFIX@ \
		-c @PREFIX@/@RM_DIR@/config/unicorn.rb \
		-E production -D
}

redmine60_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
