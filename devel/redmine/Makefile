# $NetBSD: Makefile,v 1.9 2015/04/06 08:17:26 adam Exp $

DISTNAME=	redmine-3.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RUBY_VERSION_SUPPORTED= 200 193 21 22

GEMS_DISTFILES+=	actionmailer-4.2.0.gem actionpack-4.2.0.gem
GEMS_DISTFILES+=	actionpack-action_caching-1.1.1.gem
GEMS_DISTFILES+=	actionpack-xml_parser-1.0.1.gem actionview-4.2.0.gem
GEMS_DISTFILES+=	activejob-4.2.0.gem activemodel-4.2.0.gem
GEMS_DISTFILES+=	activerecord-4.2.0.gem activesupport-4.2.0.gem
GEMS_DISTFILES+=	arel-6.0.0.gem builder-3.2.2.gem bundler-1.9.1.gem
GEMS_DISTFILES+=	coderay-1.1.0.gem erubis-2.7.0.gem globalid-0.3.3.gem
GEMS_DISTFILES+=	hike-1.2.3.gem i18n-0.7.0.gem jquery-rails-3.1.2.gem
GEMS_DISTFILES+=	json-1.8.2.gem loofah-2.0.1.gem mail-2.6.3.gem
GEMS_DISTFILES+=	mime-types-2.4.3.gem mini_portile-0.6.2.gem
GEMS_DISTFILES+=	minitest-5.5.1.gem multi_json-1.11.0.gem
GEMS_DISTFILES+=	net-ldap-0.3.1.gem nokogiri-1.6.6.2.gem
GEMS_DISTFILES+=	protected_attributes-1.0.9.gem rack-1.6.0.gem
GEMS_DISTFILES+=	rack-openid-1.4.2.gem rack-test-0.6.3.gem
GEMS_DISTFILES+=	rails-4.2.0.gem rails-deprecated_sanitizer-1.0.3.gem
GEMS_DISTFILES+=	rails-dom-testing-1.0.6.gem
GEMS_DISTFILES+=	rails-html-sanitizer-1.0.2.gem railties-4.2.0.gem
GEMS_DISTFILES+=	rake-10.4.2.gem rbpdf-1.18.5.gem redcarpet-3.1.2.gem
GEMS_DISTFILES+=	request_store-1.0.5.gem rmagick-2.13.4.gem
GEMS_DISTFILES+=	ruby-openid-2.3.0.gem sprockets-2.12.3.gem
GEMS_DISTFILES+=	sprockets-rails-2.2.4.gem thor-0.19.1.gem
GEMS_DISTFILES+=	thread_safe-0.3.5.gem tilt-1.4.1.gem tzinfo-1.2.2.gem

DISTFILES+=	${DEFAULT_DISTFILES}

.for _gem_ in ${GEMS_DISTFILES}
DISTFILES+=	${_gem_}
SITES.${_gem_}=	https://rubygems.org/downloads/
.endfor

.include "options.mk"

WRKSRC=		${WRKDIR}
RM_DIR=		share/redmine

USE_TOOLS+=	bash:run pax pkg-config

REPLACE_RUBY+=	builder-3.2.2/lib/*.rb builder-3.2.2/lib/builder/*.rb
REPLACE_RUBY+=	builder-3.2.2/rakelib/tags.rake builder-3.2.2/test/*.rb
REPLACE_RUBY+=	bundler-1.9.1/bin/*
REPLACE_RUBY+=	bundler-1.9.1/lib/bundler/templates/newgem/bin/console.tt
REPLACE_RUBY+=	bundler-1.9.1/lib/bundler/templates/newgem/exe/newgem.tt
REPLACE_RUBY+=	coderay-1.1.0/bin/coderay coderay-1.1.0/test/functional/basic.rb
REPLACE_RUBY+=	erubis-2.7.0/benchmark/bench.rb erubis-2.7.0/bin/erubis
REPLACE_RUBY+=	erubis-2.7.0/contrib/erubis erubis-2.7.0/contrib/inline-require
REPLACE_RUBY+=	erubis-2.7.0/setup.rb json-1.8.2/install.rb
REPLACE_RUBY+=	json-1.8.2/tests/*.rb json-1.8.2/tools/server.rb
REPLACE_RUBY+=	loofah-2.0.1/benchmark/benchmark.rb
REPLACE_RUBY+=	mini_portile-0.6.2/lib/mini_portile.rb
REPLACE_RUBY+=	nokogiri-1.6.6.2/bin/nokogiri
REPLACE_RUBY+=	nokogiri-1.6.6.2/ports/patches/sort-patches-by-date
REPLACE_RUBY+=	rack-1.6.0/bin/rackup rack-1.6.0/test/cgi/rackup_stub.rb
REPLACE_RUBY+=	rack-1.6.0/test/cgi/test rack-1.6.0/test/cgi/test.fcgi
REPLACE_RUBY+=	rails-4.2.0/guides/rails_guides/kindle.rb
REPLACE_RUBY+=	rails-4.2.0/guides/source/initialization.md
REPLACE_RUBY+=	railties-4.2.0/bin/rails
REPLACE_RUBY+=	raindrops-0.13.0/examples/linux-listener-stats.rb
REPLACE_RUBY+=	rake-10.4.2/bin/rake rake-10.4.2/doc/proto_rake.rdoc
REPLACE_RUBY+=	rake-10.4.2/test/test_rake_file_utils.rb
REPLACE_RUBY+=	rbpdf-1.18.5/test/test_helper.rb redcarpet-3.1.2/bin/redcarpet
REPLACE_RUBY+=	redmine-3.0.1/bin/*
REPLACE_RUBY+=	redmine-3.0.1/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	redmine-3.0.1/extra/svn/reposman.rb
REPLACE_RUBY+=	redmine-3.0.1/public/dispatch.fcgi.example
REPLACE_RUBY+=	redmine-3.0.1/script/* rmagick-2.13.4/doc/ex/*.rb
REPLACE_RUBY+=	rmagick-2.13.4/doc/usage.html rmagick-2.13.4/examples/*.rb
REPLACE_RUBY+=	rmagick-2.13.4/test/*.rb ruby-openid-2.3.0/examples/discover
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.cgi
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.fcgi
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.rb
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/script/rails
REPLACE_RUBY+=	sprockets-2.12.3/bin/sprockets thor-0.19.1/bin/thor
REPLACE_RUBY+=	thread_safe-0.3.5/examples/bench_cache.rb tilt-1.4.1/bin/tilt
REPLACE_RUBY+=	unicorn-4.8.3/GIT-VERSION-GEN
REPLACE_RUBY+=	unicorn-4.8.3/bin/unicorn*
REPLACE_RUBY+=	unicorn-4.8.3/script/isolate_for_tests
REPLACE_RUBY+=	unicorn-4.8.3/t/bin/content-md5-put
REPLACE_RUBY+=	unicorn-4.8.3/t/bin/sha1sum.rb unicorn-4.8.3/t/bin/unused_listen
REPLACE_RUBY+=	unicorn-4.8.3/test/aggregate.rb

CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/bundler-*/lib/bundler/templates/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/rack-*/test/cgi/test.ru
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/json-1.8.2/json-java.gemspec
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/nokogiri-1.6.6.2/ports/patches/sort-patches-by-date
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/loofah-2.0.1/benchmark/benchmark.rb

# Selenium has Linux .so files.
CHECK_SHLIBS_SUPPORTED=	no

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	pre-configure
SUBST_MESSAGE.rake=	Replacing path to rake programme.
SUBST_FILES.rake=	redmine-3.0.1/Rakefile
SUBST_FILES.rake+=	actionpack-action_caching-1.1.1/Rakefile
SUBST_FILES.rake+=	ruby-openid-2.3.0/examples/rails_openid/Rakefile
SUBST_SED.rake=		-e 's,/usr/bin/env rake,${PREFIX}/${RM_DIR}/gems/bin/rake,g'

REPLACE_BASH+=	nokogiri-1.6.6.2/build_all nokogiri-1.6.6.2/test_all
REPLACE_BASH+=	bundler-1.9.1/lib/bundler/templates/newgem/bin/setup.tt
REPLACE_BASH+=	unicorn-4.8.3/local.mk.sample

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
	find ${DESTDIR} -type f -print0 | xargs -0 chmod g+r,-x

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
