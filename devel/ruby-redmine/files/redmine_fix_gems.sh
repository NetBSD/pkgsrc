#!/bin/sh

GEM_HOME=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems
GEM_PATH=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems

export GEM_HOME GEM_PATH

cd @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app

@GEM@ install nokogiri --version 1.6.6.2 -- --use-system-libraries --with-xml2-config=@PREFIX@/bin/xml2-config --with-xslt-config=@PREFIX@/bin/xslt-config
@GEM@ pristine json --version 1.8.3
@GEM@ pristine kgio --version 2.9.3
@GEM@ pristine mysql2 --version 0.3.18
@GEM@ pristine raindrops --version 0.13.0
@GEM@ pristine redcarpet --version 3.1.2
@GEM@ pristine rmagick --version 2.15.3
@GEM@ pristine unicorn --version 4.9.0
