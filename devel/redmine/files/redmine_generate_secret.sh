#!/bin/sh

cd @PREFIX@/share/redmine/app

GEM_HOME=@PREFIX@/share/redmine/gems \
  GEM_PATH=@PREFIX@/share/redmine/gems \
    @RUBY@ bin/rake secret RAILS_ENV=production
