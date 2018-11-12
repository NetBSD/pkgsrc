# $NetBSD: Makefile,v 1.34 2018/11/12 03:51:55 ryoon Exp $

DISTNAME=	redmine-3.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	12
PREV_PKGPATH=	devel/redmine
CATEGORIES=	devel
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

# nokogirl version required is broken in Ruby 2.3
# Ruby 2.4 will be supported by Redmine 3.4.
RUBY_VERSIONS_ACCEPTED=	22

.include "../../lang/ruby/rubyversion.mk"

GEMS_DISTFILES+=	actionmailer-4.2.7.1.gem actionpack-4.2.7.1.gem
GEMS_DISTFILES+=	actionpack-action_caching-1.1.1.gem
GEMS_DISTFILES+=	actionpack-xml_parser-1.0.2.gem actionview-4.2.7.1.gem
GEMS_DISTFILES+=	activejob-4.2.7.1.gem activemodel-4.2.7.1.gem
GEMS_DISTFILES+=	activerecord-4.2.7.1.gem activesupport-4.2.7.1.gem
GEMS_DISTFILES+=	addressable-2.5.0.gem arel-6.0.3.gem builder-3.2.2.gem
GEMS_DISTFILES+=	bundler-1.10.6.gem capybara-2.11.0.gem
GEMS_DISTFILES+=	childprocess-0.5.9.gem coderay-1.1.1.gem
GEMS_DISTFILES+=	css_parser-1.4.7.gem docile-1.1.5.gem
GEMS_DISTFILES+=	erubis-2.7.0.gem ffi-1.9.14.gem globalid-0.3.7.gem
GEMS_DISTFILES+=	hike-1.2.3.gem htmlentities-4.3.1.gem i18n-0.7.0.gem
GEMS_DISTFILES+=	jquery-rails-3.1.4.gem json-1.8.3.gem loofah-2.0.3.gem
GEMS_DISTFILES+=	mail-2.6.4.gem mime-types-3.1.gem
GEMS_DISTFILES+=	mime-types-data-3.2016.0521.gem mimemagic-0.3.2.gem
GEMS_DISTFILES+=	mini_portile2-2.0.0.gem minitest-5.8.3.gem
GEMS_DISTFILES+=	multi_json-1.12.1.gem net-ldap-0.12.1.gem
GEMS_DISTFILES+=	nokogiri-1.6.7.2.gem protected_attributes-1.1.3.gem
GEMS_DISTFILES+=	public_suffix-2.0.4.gem rack-1.6.4.gem
GEMS_DISTFILES+=	rack-openid-1.4.2.gem rack-test-0.6.3.gem
GEMS_DISTFILES+=	rails-4.2.7.1.gem rails-deprecated_sanitizer-1.0.3.gem
GEMS_DISTFILES+=	rails-dom-testing-1.0.7.gem
GEMS_DISTFILES+=	rails-html-sanitizer-1.0.3.gem railties-4.2.7.1.gem
GEMS_DISTFILES+=	rake-10.4.2.gem rbpdf-1.19.0.gem rbpdf-font-1.19.0.gem
GEMS_DISTFILES+=	rdoc-4.3.0.gem redcarpet-3.3.4.gem
GEMS_DISTFILES+=	request_store-1.0.5.gem rmagick-2.16.0.gem
GEMS_DISTFILES+=	roadie-3.2.0.gem roadie-rails-1.1.1.gem
GEMS_DISTFILES+=	ruby-openid-2.3.0.gem selenium-webdriver-2.53.4.gem
GEMS_DISTFILES+=	simplecov-0.9.2.gem sprockets-3.4.0.gem
GEMS_DISTFILES+=	sprockets-rails-3.2.0.gem thor-0.19.4.gem
GEMS_DISTFILES+=	thread_safe-0.3.5.gem tilt-1.4.1.gem tzinfo-1.2.2.gem
GEMS_DISTFILES+=	tzinfo-data-1.2016.10.gem websocket-1.2.3.gem
GEMS_DISTFILES+=	xpath-2.0.0.gem yard-0.9.5.gem

DISTFILES+=	${DEFAULT_DISTFILES}

.include "options.mk"

.for _gem_ in ${GEMS_DISTFILES}
DISTFILES+=	${_gem_}
SITES.${_gem_}=	https://rubygems.org/downloads/
.endfor

WRKSRC=		${WRKDIR}
RM_DIR=		share/${RUBY_PKGPREFIX}-redmine

USE_TOOLS+=	bash:run pax pkg-config

REPLACE_RUBY+=	builder-3.2.2/lib/*.rb builder-3.2.2/lib/builder/*.rb
REPLACE_RUBY+=	builder-3.2.2/rakelib/tags.rake builder-3.2.2/test/*.rb
REPLACE_RUBY+=	bundler-1.10.6/bin/*
REPLACE_RUBY+=	bundler-1.10.6/lib/bundler/templates/newgem/bin/console.tt
REPLACE_RUBY+=	bundler-1.10.6/lib/bundler/templates/newgem/exe/newgem.tt
REPLACE_RUBY+=	coderay-1.1.1/bin/coderay coderay-1.1.1/test/functional/basic.rb
REPLACE_RUBY+=	erubis-2.7.0/benchmark/bench.rb erubis-2.7.0/bin/erubis
REPLACE_RUBY+=	erubis-2.7.0/contrib/erubis erubis-2.7.0/contrib/inline-require
REPLACE_RUBY+=	erubis-2.7.0/setup.rb json-1.8.3/install.rb
REPLACE_RUBY+=	json-1.8.3/tests/*.rb json-1.8.3/tools/server.rb
REPLACE_RUBY+=	loofah-2.0.3/benchmark/benchmark.rb
REPLACE_RUBY+=	nokogiri-1.6.7.2/bin/nokogiri
REPLACE_RUBY+=	nokogiri-1.6.7.2/patches/sort-patches-by-date
REPLACE_RUBY+=	rack-1.6.4/bin/rackup rack-1.6.4/test/cgi/rackup_stub.rb
REPLACE_RUBY+=	rack-1.6.4/test/cgi/test rack-1.6.4/test/cgi/test.fcgi
REPLACE_RUBY+=	rails-4.2.7.1/guides/rails_guides/kindle.rb
REPLACE_RUBY+=	rails-4.2.7.1/guides/source/initialization.md
REPLACE_RUBY+=	railties-4.2.7.1/bin/rails
REPLACE_RUBY+=	raindrops-0.17.0/examples/linux-listener-stats.rb
REPLACE_RUBY+=	rake-10.4.2/bin/rake rake-10.4.2/doc/proto_rake.rdoc
REPLACE_RUBY+=	rake-10.4.2/test/test_rake_file_utils.rb
REPLACE_RUBY+=	rbpdf-1.19.0/test/test_helper.rb redcarpet-3.3.4/bin/redcarpet
REPLACE_RUBY+=	${DISTNAME}/bin/*
REPLACE_RUBY+=	${DISTNAME}/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	${DISTNAME}/extra/svn/reposman.rb
REPLACE_RUBY+=	${DISTNAME}/public/dispatch.fcgi.example
REPLACE_RUBY+=	${DISTNAME}/script/* rmagick-2.16.0/doc/ex/*.rb
REPLACE_RUBY+=	rmagick-2.16.0/doc/usage.html rmagick-2.16.0/examples/*.rb
REPLACE_RUBY+=	rmagick-2.16.0/test/*.rb ruby-openid-2.3.0/examples/discover
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.cgi
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.fcgi
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/public/dispatch.rb
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/script/rails
REPLACE_RUBY+=	sprockets-3.4.0/bin/sprockets thor-0.19.4/bin/thor
REPLACE_RUBY+=	thread_safe-0.3.5/examples/bench_cache.rb tilt-1.4.1/bin/tilt
REPLACE_RUBY+=	unicorn-5.2.0/GIT-VERSION-GEN
REPLACE_RUBY+=	unicorn-5.2.0/bin/unicorn*
REPLACE_RUBY+=	unicorn-5.2.0/t/bin/content-md5-put
REPLACE_RUBY+=	unicorn-5.2.0/t/bin/sha1sum.rb unicorn-5.2.0/t/bin/unused_listen
REPLACE_RUBY+=	unicorn-5.2.0/test/aggregate.rb

CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/bundler-*/lib/bundler/templates/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/rack-*/test/cgi/test.ru
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/json-1.8.3/json-java.gemspec
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/nokogiri-1.6.7.2/ports/patches/sort-patches-by-date
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/loofah-2.0.3/benchmark/benchmark.rb

# Selenium has Linux .so files.
CHECK_SHLIBS_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

SUBST_CLASSES+=		pkgcfg
SUBST_FILES.pkgcfg=	rmagick-2.16.0/ext/RMagick/extconf.rb
SUBST_MESSAGE.pkgcfg=	Fixing ImageMagick pkg-config paths.
SUBST_SED.pkgcfg=	-e 's|Magick-config|Magick-config6|g'
SUBST_SED.pkgcfg+=	-e 's|MagickWand-config|MagickWand-config6|g'
SUBST_SED.pkgcfg+=	-e 's|MagickWand`|MagickWand-6.Q16`|g'
SUBST_SED.pkgcfg+=	-e 's|MagickCore|MagickCore-6.Q16|g'
SUBST_STAGE.pkgcfg=	pre-configure

SUBST_CLASSES+=		rake
SUBST_STAGE.rake=	pre-configure
SUBST_MESSAGE.rake=	Replacing path to rake programme.
SUBST_FILES.rake=	${DISTNAME}/Rakefile
SUBST_FILES.rake+=	actionpack-action_caching-1.1.1/Rakefile
SUBST_FILES.rake+=	ruby-openid-2.3.0/examples/rails_openid/Rakefile
SUBST_SED.rake=		-e "s|/usr/bin/env rake|${PREFIX}/${RM_DIR}/gems/bin/rake|g"

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${DESTDIR}${PREFIX}/bin/redmine_*${RUBY_SUFFIX}.sh
SUBST_MESSAGE.shell=	Fixing paths in helper shell scripts.
SUBST_SED.shell=	-e "s|@PREFIX@|${PREFIX}|g;s|@GEM@|${GEM}|g"
SUBST_SED.shell+=	-e "s|@RUBY@|${RUBY}|g"
SUBST_SED.shell+=	-e "s|@RUBY_PKGPREFIX@|${RUBY_PKGPREFIX}|g"
SUBST_STAGE.shell=	post-install

REPLACE_BASH+=	nokogiri-1.6.7.2/build_all nokogiri-1.6.7.2/test_all
REPLACE_BASH+=	bundler-1.10.6/lib/bundler/templates/newgem/bin/setup.tt

GEM_HOME=	${RM_DIR}/gems
MESSAGE_SUBST+=	RM_DIR=${RM_DIR}
PLIST_SUBST+=	GEM_HOME=${GEM_HOME}

USE_LANGUAGES=	c
# Do not build internal libxml2 and libxslt.
MAKE_ENV+=	NOKOGIRI_USE_SYSTEM_LIBRARIES=yes
EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine

INSTALLATION_DIRS+=	bin ${EGDIR} ${RM_DIR}/app/.bundle \
			${RM_DIR}/app/config

CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${RM_DIR}/app/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${RM_DIR}/app/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${RM_DIR}/app/config/additional_environment.rb

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

pre-configure:
	${RUBY} ${.CURDIR}/${UPDATE_GEMSPEC} ${WRKDIR}/tilt-1.4.1.gemspec rdoc:

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
	${INSTALL_DATA} ${FILESDIR}/bundle-config \
		${DESTDIR}${PREFIX}/${RM_DIR}/app/.bundle/config
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_fix_gems.sh \
		${DESTDIR}${PREFIX}/bin/redmine_fix_gems${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_generate_secret.sh \
		${DESTDIR}${PREFIX}/bin/redmine_generate_secret${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_DATA} ${FILESDIR}/Gemfile.lock \
		${DESTDIR}${PREFIX}/${RM_DIR}/app
	${INSTALL_DATA} ${FILESDIR}/secrets.yml \
		${DESTDIR}${PREFIX}/${RM_DIR}/app/config
#	XXX: Rewrite this to use ${INSTALL_DATA} and remove pax from USE_TOOLS
	cd ${WRKDIR}/${DISTNAME} && pax -rw -pmp . \
		${DESTDIR}${PREFIX}/${RM_DIR}/app
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/redmine_*${RUBY_SUFFIX}.sh

post-install: unicorn-post-install
	find ${DESTDIR} -name .cvsignore -type f | xargs rm -rf
	find ${DESTDIR} -name .gitignore -type f | xargs rm -rf
	find ${DESTDIR} -name .hgignore -type f | xargs rm -rf
	find ${DESTDIR} -name ext -type d | xargs rm -rf
	find ${DESTDIR} -name mkmf.log -type f | xargs rm -rf
	find ${DESTDIR} -name gem_make.out -type f | xargs rm -rf
	find ${DESTDIR} -name gem.build_complete -type f | xargs rm -rf
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/configuration.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/database.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/app/config/additional_environment.rb.example \
		${DESTDIR}/${EGDIR}
	find ${DESTDIR}${PREFIX}/share/${RUBY_PKGPREFIX}-redmine -type f -print0 \
		| xargs -0 chmod g+r,g-w,-x,o-w
	find ${DESTDIR}${PREFIX}/share/${RUBY_PKGPREFIX}-redmine -type d -print0 \
		| xargs -0 chmod g-w

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
