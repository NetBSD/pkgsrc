#!/bin/sh

cd @PREFIX@/@RM_DIR@

@RUBY@ bin/rake redmine:load_default_data RAILS_ENV=production
