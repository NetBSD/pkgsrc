#!/bin/sh
#
# $NetBSD: redmine50_unicorn.sh,v 1.1 2022/09/03 13:53:59 taca Exp $
#

# PROVIDE: redmine42_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="redmine42_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine42_unicorn_start"
stop_cmd="redmine42_unicorn_stop"

redmine42_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@
	@PREFIX@/bin/unicorn@RUBY_SUFFIX@ \
		-c @PREFIX@/@RM_DIR@/config/unicorn.rb \
		-E production -D
}

redmine42_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
