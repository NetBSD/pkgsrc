# $NetBSD: Makefile,v 1.5 2015/03/29 08:30:01 ryoon Exp $

DISTNAME=	redmine-3.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RUBY_VERSION_SUPPORTED= 200 193 21

GEMS_DISTFILES+=bundler-1.9.1.gem \
		i18n-0.7.0.gem \
		json-1.8.2.gem \
		minitest-5.5.1.gem \
		thread_safe-0.3.5.gem \
		tzinfo-1.2.2.gem \
		activesupport-4.2.0.gem \
		builder-3.2.2.gem \
		erubis-2.7.0.gem \
		mini_portile-0.6.2.gem \
		nokogiri-1.6.6.2.gem \
		rails-deprecated_sanitizer-1.0.3.gem \
		rails-dom-testing-1.0.6.gem \
		loofah-2.0.1.gem \
		rails-html-sanitizer-1.0.2.gem \
		actionview-4.2.0.gem \
		rack-1.6.0.gem \
		rack-test-0.6.3.gem \
		actionpack-4.2.0.gem \
		globalid-0.3.3.gem \
		activejob-4.2.0.gem \
		mime-types-2.4.3.gem \
		mail-2.6.3.gem \
		actionmailer-4.2.0.gem \
		actionpack-action_caching-1.1.1.gem \
		actionpack-xml_parser-1.0.1.gem \
		activemodel-4.2.0.gem \
		arel-6.0.0.gem \
		activerecord-4.2.0.gem \
		coderay-1.1.0.gem \
		hike-1.2.3.gem \
		thor-0.19.1.gem \
		railties-4.2.0.gem \
		jquery-rails-3.1.2.gem \
		multi_json-1.11.0.gem \
		net-ldap-0.3.1.gem \
		protected_attributes-1.0.9.gem \
		ruby-openid-2.3.0.gem \
		rack-openid-1.4.2.gem \
		tilt-1.4.1.gem \
		sprockets-2.12.3.gem \
		sprockets-rails-2.2.4.gem \
		rails-4.2.0.gem \
		rbpdf-1.18.5.gem \
		redcarpet-3.1.2.gem \
		request_store-1.0.5.gem \
		rmagick-2.13.4.gem \
		rake-10.4.2.gem
		

DISTFILES+=	${DEFAULT_DISTFILES}

.for _gem_ in ${GEMS_DISTFILES}
DISTFILES+=	${_gem_}
SITES.${_gem_}=	https://rubygems.org/downloads/
.endfor

RUBY_VERSION_SUPPORTED= 22

.include "options.mk"

WRKSRC=		${WRKDIR}
RM_DIR=		share/redmine

USE_TOOLS+=	pax pkg-config

REPLACE_RUBY+=	builder-*/lib/*
REPLACE_RUBY+=	builder-*/lib/builder/*
REPLACE_RUBY+=	builder-*/test/*
REPLACE_RUBY+=	bundler-*/lib/bundler/templates/*/*/*
REPLACE_RUBY+=	bundler-*/bin/*
REPLACE_RUBY+=	erubis-*/benchmark/bench.rb
REPLACE_RUBY+=	ffi-*/ext/ffi_c/extconf.rb
REPLACE_RUBY+=	rbpdf-*/test/test_helper.rb
REPLACE_RUBY+=	rmagick-*/doc/ex/*
REPLACE_RUBY+=	rmagick-*/examples/*
REPLACE_RUBY+=	rmagick-*/test/*
REPLACE_RUBY+=	ruby-openid-*/examples/*
REPLACE_RUBY+=	ruby-openid-*/examples/rails_openid/*
REPLACE_RUBY+=	ruby-openid-*/examples/rails_openid/*/*
REPLACE_RUBY+=	ruby-openid-*/examples/rails_openid/*/*/*
REPLACE_RUBY+=	rubyzip-*/test/data/*
REPLACE_RUBY+=	redmine-*/*
REPLACE_RUBY+=	redmine-*/bin/*
REPLACE_RUBY+=	redmine-*/app/*
REPLACE_RUBY+=	redmine-*/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	redmine-*/extra/svn/reposman.rb
REPLACE_RUBY+=	redmine-*/public/dispatch.fcgi.example
REPLACE_RUBY+=	redmine-*/script/*
REPLACE_RUBY+=	coderay-*/bin/coderay
REPLACE_RUBY+=	erubis-*/bin/*
REPLACE_RUBY+=	erubis-*/contrib/*
REPLACE_RUBY+=	mocha-*/bin/build-matrix
REPLACE_RUBY+=	nokogiri-*/*
REPLACE_RUBY+=	nokogiri-*/bin/*
REPLACE_RUBY+=	nokogiri-*/test/*
REPLACE_RUBY+=	rack-*/bin/*
REPLACE_RUBY+=	rack-*/test/*
REPLACE_RUBY+=	rack-*/test/cgi/*
REPLACE_RUBY+=	railties-*/bin/*
REPLACE_RUBY+=	railties-*/guides/code/getting_started/*
REPLACE_RUBY+=	railties-*/guides/code/getting_started/script/*
REPLACE_RUBY+=	railties-*/lib/rails/generators/rails/app/templates/Rakefile
REPLACE_RUBY+=	railties-*/lib/rails/generators/rails/plugin_new/templates/Rakefile
REPLACE_RUBY+=	rake-*/bin/rake
REPLACE_RUBY+=	redcarpet-*/bin/redcarpet
REPLACE_RUBY+=	rmagick-*/doc/ex/*
REPLACE_RUBY_DIRS+=	ruby-openid-*
REPLACE_RUBY+=	rubyzip-*/*/*
REPLACE_RUBY+=	shoulda-context-*/bin/*
REPLACE_RUBY+=	sprockets-*/bin/*
REPLACE_RUBY+=	thor-*/bin/*
REPLACE_RUBY+=	tilt-*/bin/*
REPLACE_RUBY+=	treetop-*/bin/*
REPLACE_RUBY+=	yard-*/bin/*
REPLACE_RUBY+=	pg-*/*
REPLACE_RUBY+=	pg-*/lib/*
REPLACE_RUBY+=	pg-*/lib/pg/*
REPLACE_RUBY+=	pg-*/sample/*
REPLACE_RUBY+=	json-*/*
REPLACE_RUBY+=	json-*/tests/*
REPLACE_RUBY+=	json-*/tools/*
REPLACE_RUBY+=	rdoc-*/bin/*
REPLACE_RUBY+=	unicorn-*/*
REPLACE_RUBY+=	unicorn-*/bin/*
REPLACE_RUBY+=	unicorn-*/script/*
REPLACE_RUBY+=	unicorn-*/t/bin/*
REPLACE_RUBY+=	unicorn-*/test/*
REPLACE_RUBY+=	raindrops-*/examples/*
REPLACE_RUBY+=	thread_safe-*/examples/*

CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/bundler-*/lib/bundler/templates/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/rack-*/test/cgi/test.ru
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/pg-*/spec/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/pg-*/spec/pg/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/nokogiri-1.6.6.2/ports/patches/sort-patches-by-date
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/loofah-2.0.1/benchmark/benchmark.rb

# Selenium has Linux .so files.
CHECK_SHLIBS_SUPPORTED=	no

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	pre-configure
SUBST_MESSAGE.rake=	Replace rake
SUBST_FILES.rake=	${REPLACE_RUBY}
SUBST_SED.rake=		-e 's,/usr/bin/env rake,${PREFIX}/${RM_DIR}/gems/bin/rake,g'
SUBST_SED.rake+=	-e 's,/usr/bin/env bash,/bin/sh,g'

GEM_HOME=	${RM_DIR}/gems
PLIST_SUBST=	GEM_HOME=${GEM_HOME}

USE_LANGUAGES=	c
# Do not build internal libxml2 and libxslt.
MAKE_ENV+=	NOKOGIRI_USE_SYSTEM_LIBRARIES=yes

INSTALLATION_DIRS=	share/examples/redmine share/redmine/app/.bundle

EGDIR=		${PREFIX}/share/examples/redmine
CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${PREFIX}/${RM_DIR}/app/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${PREFIX}/${RM_DIR}/app/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${PREFIX}/${RM_DIR}/app/config/additional_environment.rb

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RM_DIR=${RM_DIR}

GEM_EXTSDIR_NEEDS_SUBDIR=	no
.include "../../lang/ruby/gem-extract.mk"

do-build:
.for _gem_ in ${DISTFILES:M*.gem:S/.gem$//g}
	${RUN} cd ${WRKDIR}/${_gem_} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} build ../${_gem_}.gemspec
	${RUN} ${TEST} -f ${WRKDIR}/${_gem_}/${_gem_}.gem || \
		${FAIL_MSG} "Build of ${_gem_}.gem failed."
.endfor

RUBYGEM_INSTALL_ROOT=	${WRKDIR}/.inst
RUBYGEM_INSTALL_ROOT_OPTION=	--install-root ${RUBYGEM_INSTALL_ROOT}
_RUBYGEM_OPTIONS=	--no-update-sources     # don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${PREFIX}/${GEM_HOME}
_RUBYGEM_OPTIONS+=	${RUBYGEM_INSTALL_ROOT_OPTION}
_RUBYGEM_OPTIONS+=	--ignore-dependencies
_RUBYGEM_OPTIONS+=	--no-ri --no-rdoc

.include "../../lang/ruby/rubyversion.mk"

do-install:
# Install gems
.for _gem_ in ${DISTFILES:M*.gem:S/.gem$//g}
	@${STEP_MSG} "Installing gem into installation root"
	${RUN} ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} install --backtrace ${RUBYGEM_OPTIONS} \
			${_RUBYGEM_OPTIONS} --local ${WRKDIR}/${_gem_}/${_gem_}.gem
	@${STEP_MSG} "gem install"

	${RUN} cd ${RUBYGEM_INSTALL_ROOT}${PREFIX} && \
		pax -rwpp . ${DESTDIR}${PREFIX}
.endfor
# Install Redmine
	cd ${WRKDIR}/${DISTNAME} && pax -rw -pmp . \
		${DESTDIR}${PREFIX}/${RM_DIR}/app
	${CP} ${FILESDIR}/Gemfile.lock \
		${DESTDIR}${PREFIX}/share/redmine/app
	${CP} ${FILESDIR}/bundle-config \
		${DESTDIR}${PREFIX}/share/redmine/app/.bundle/config

post-install: unicorn-post-install
	find ${DESTDIR} -name ext -type d | xargs rm -rf
	find ${DESTDIR} -name mkmf.log -type f | xargs rm -rf
	find ${DESTDIR} -name gem_make.out -type f | xargs rm -rf
	find ${DESTDIR} -name gem.build_complete -type f | xargs rm -rf
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/configuration.yml.example \
		${DESTDIR}${PREFIX}/share/examples/redmine
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/database.yml.example \
		${DESTDIR}${PREFIX}/share/examples/redmine
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/additional_environment.rb.example \
		${DESTDIR}${PREFIX}/share/examples/redmine


.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
