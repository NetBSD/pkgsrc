#!/bin/sh
#
# $NetBSD: redmine_unicorn.sh,v 1.2 2021/02/28 16:01:05 taca Exp $
#

# PROVIDE: redmine_unicorn@RUBY_SUFFIX@
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="redmine_unicorn@RUBY_SUFFIX@"
rcvar=$name
start_cmd="redmine_unicorn_start"
stop_cmd="redmine_unicorn_stop"

redmine_unicorn_start()
{
	cd @PREFIX@/@RM_DIR@/app
	GEM_HOME=@PREFIX@/@RM_DIR@/gems \
	GEM_PATH=@PREFIX@/@RM_DIR@/gems \
		@RUBY@ \
		@PREFIX@/@RM_DIR@/gems/bin/bundle exec unicorn \
		-c @PREFIX@/@RM_DIR@/app/config/unicorn.rb \
		-E production -D
}

redmine_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/@RM_DIR@/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
