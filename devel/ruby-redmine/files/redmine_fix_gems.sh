#!/bin/sh

GEM_HOME=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems
GEM_PATH=@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/gems
PATH=@PREFIX@/sbin:@PREFIX@/bin:${PATH}
NOKOGIRI_USE_SYSTEM_LIBRARIES=yes

export GEM_HOME GEM_PATH PATH NOKOGIRI_USE_SYSTEM_LIBRARIES

cd @PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app

@GEM@ pristine nokogiri --version 1.6.7.2 -- --use-system-libraries --with-xml2-onfig=@PREFIX@/bin/xml2-config --with-libxslt-config=@PREFIX@/bin/xslt-config
@GEM@ pristine ffi --version 1.9.14
@GEM@ pristine json --version 1.8.3
@GEM@ pristine kgio --version 2.11.0
@GEM@ pristine mysql2 --version 0.3.21
@GEM@ pristine raindrops --version 0.17.0
@GEM@ pristine redcarpet --version 3.3.4
@GEM@ pristine rmagick --version 2.16.0
@GEM@ pristine unicorn --version 5.2.0
