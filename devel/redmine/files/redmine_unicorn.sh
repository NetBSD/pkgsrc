#!/bin/sh
#
# $NetBSD: redmine_unicorn.sh,v 1.2 2015/04/26 15:45:36 rodent Exp $
#

# PROVIDE: redmine_unicorn
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="redmine_unicorn"
rcvar=$name
start_cmd="redmine_unicorn_start"
stop_cmd="redmine_unicorn_stop"

redmine_unicorn_start()
{
	cd @PREFIX@/share/redmine/app
	GEM_HOME=@PREFIX@/share/redmine/gems \
	GEM_PATH=@PREFIX@/share/redmine/gems \
		@RUBY@ \
		@PREFIX@/share/redmine/gems/bin/bundle exec unicorn \
		-c @PREFIX@/share/redmine/app/config/unicorn.rb \
		-E production -D
}

redmine_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/share/redmine/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
