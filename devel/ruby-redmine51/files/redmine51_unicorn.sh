#!/bin/sh
#
# $NetBSD: redmine51_unicorn.sh,v 1.1 2023/11/29 16:10:19 taca Exp $
#

# PROVIDE: redmine51_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="redmine51_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine51_unicorn_start"
stop_cmd="redmine51_unicorn_stop"

redmine51_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@
	@PREFIX@/bin/bundle@RUBY_SUFFIX@ exec @PREFIX@/bin/unicorn@RUBY_SUFFIX@ \
		-c @PREFIX@/@RM_DIR@/config/unicorn.rb \
		-E production -D
}

redmine51_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
