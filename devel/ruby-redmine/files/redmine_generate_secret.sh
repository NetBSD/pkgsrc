#!/bin/sh

cd @PREFIX@/@RM_DIR@/app

GEM_HOME=@PREFIX@/@RM_DIR@/gems \
  GEM_PATH=@PREFIX@/@RM_DIR@/gems \
    @RUBY@ bin/rake secret RAILS_ENV=production
