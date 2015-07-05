#!/bin/sh
#
# $NetBSD: redmine_unicorn.sh,v 1.1 2015/07/05 23:55:25 rodent Exp $
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
	cd @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app
	GEM_HOME=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems \
	GEM_PATH=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems \
		@RUBY@ \
		@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems/bin/bundle exec unicorn \
		-c @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app/config/unicorn.rb \
		-E production -D
}

redmine_unicorn_stop()
{
	/bin/kill -QUIT `/bin/cat @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/unicorn.pid`
}

load_rc_config $name
run_rc_command "$1"
