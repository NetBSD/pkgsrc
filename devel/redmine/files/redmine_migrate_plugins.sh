#!/bin/sh

/etc/rc.d/redmine_unicorn status > /dev/null 2>&1

if [ $? -eq 0 ]; then
	echo 'Please, stop Redmine unicorn before running this script.'
	exit 1
fi

cd @PREFIX@/share/redmine/app/plugins

GEM_HOME=@PREFIX@/share/redmine/gems \
  GEM_PATH=@PREFIX@/share/redmine/gems \
    @RUBY@ ../bin/rake redmine:plugins:migrate RAILS_ENV=production
