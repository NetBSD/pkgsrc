#!/bin/sh

GEM_HOME=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems
GEM_PATH=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems
PATH=@PREFIX@/sbin:@PREFIX@/bin:${PATH}

export GEM_HOME GEM_PATH PATH

cd @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app

@GEM@ pristine nokogiri --version 1.6.6.4 -- --use-system-libraries --with-xml2-config=@PREFIX@/bin/xml2-config --with-xslt-config=@PREFIX@/bin/xslt-config
@GEM@ pristine json --version 1.8.3
@GEM@ pristine kgio --version 2.10.0
@GEM@ pristine mysql2 --version 0.3.20
@GEM@ pristine raindrops --version 0.15.0
@GEM@ pristine redcarpet --version 3.3.3
@GEM@ pristine rmagick --version 2.15.4
@GEM@ pristine unicorn --version 5.0.1
