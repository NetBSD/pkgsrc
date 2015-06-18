#!/bin/sh

cd @PREFIX@/share/redmine/app

GEM_HOME=@PREFIX@/share/redmine/gems \
  GEM_PATH=@PREFIX@/share/redmine/gems \
    @RUBY@ bin/rake db:migrate RAILS_ENV=production
