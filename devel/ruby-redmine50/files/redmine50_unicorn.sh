#!/bin/sh
#
# $NetBSD: redmine50_unicorn.sh,v 1.4 2023/04/28 08:25:43 triaxx Exp $
#

# PROVIDE: redmine50_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f @SYSCONFBASE@/rc.subr ]; then
	$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
fi

name="redmine50_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine50_unicorn_start"
stop_cmd="redmine50_unicorn_stop"

redmine50_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@
	@PREFIX@/bin/bundle@RUBY_SUFFIX@ exec @PREFIX@/bin/unicorn@RUBY_SUFFIX@ \
		-c @PREFIX@/@RM_DIR@/config/unicorn.rb \
		-E production -D
}

redmine50_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
