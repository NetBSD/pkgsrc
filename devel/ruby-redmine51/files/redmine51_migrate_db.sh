#!/bin/sh

cd @PREFIX@/@RM_DIR@

@RUBY@ bin/rake db:migrate RAILS_ENV=production
