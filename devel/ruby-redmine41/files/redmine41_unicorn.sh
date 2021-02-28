#!/bin/sh
#
# $NetBSD: redmine41_unicorn.sh,v 1.1 2021/02/28 16:50:03 taca Exp $
#

# PROVIDE: redmine41_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="redmine41_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine41_unicorn_start"
stop_cmd="redmine41_unicorn_stop"

redmine41_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@
	@PREFIX@/bin/unicorn@RUBY_SUFFIX@ \
		-c @PREFIX@/@RM_DIR@/config/unicorn.rb \
		-E production -D
}

redmine41_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
