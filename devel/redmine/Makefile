# $NetBSD: Makefile,v 1.2 2015/01/25 13:09:10 joerg Exp $

DISTNAME=	redmine-2.6.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.redmine.org/releases/
MASTER_SITES+=	https://rubygems.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.

RUBY_VERSION_SUPPORTED= 200 193 21

DISTFILES+=	${DEFAULT_DISTFILES} \
		actionmailer-3.2.19.gem \
		actionpack-3.2.19.gem \
		activemodel-3.2.19.gem \
		activerecord-3.2.19.gem \
		activeresource-3.2.19.gem \
		activesupport-3.2.19.gem \
		arel-3.0.3.gem \
		builder-3.0.4.gem \
		bundler-1.7.10.gem \
		capybara-2.1.0.gem \
		childprocess-0.5.5.gem \
		coderay-1.1.0.gem \
		erubis-2.7.0.gem \
		ffi-1.9.6.gem \
		hike-1.2.3.gem \
		i18n-0.7.0.gem \
		journey-1.0.4.gem \
		jquery-rails-3.1.2.gem \
		json-1.8.1.gem \
		mail-2.5.4.gem \
		metaclass-0.0.4.gem \
		mime-types-1.25.1.gem \
		mini_portile-0.6.2.gem \
		mocha-1.0.0.gem \
		multi_json-1.10.1.gem \
		net-ldap-0.3.1.gem \
		nokogiri-1.6.5.gem \
		polyglot-0.3.5.gem \
		rack-1.4.5.gem \
		rack-cache-1.2.gem \
		rack-openid-1.4.2.gem \
		rack-ssl-1.3.4.gem \
		rack-test-0.6.2.gem \
		rails-3.2.19.gem \
		railties-3.2.19.gem \
		rake-10.4.2.gem \
		rbpdf-1.18.4.gem \
		rdoc-3.12.2.gem \
		redcarpet-2.3.0.gem \
		request_store-1.0.5.gem \
		rmagick-2.13.4.gem \
		ruby-openid-2.3.0.gem \
		rubyzip-1.1.6.gem \
		selenium-webdriver-2.44.0.gem \
		shoulda-3.3.2.gem \
		shoulda-context-1.0.2.gem \
		shoulda-matchers-1.4.1.gem \
		sprockets-2.2.3.gem \
		thor-0.19.1.gem \
		tilt-1.4.1.gem \
		treetop-1.4.15.gem \
		tzinfo-0.3.42.gem \
		websocket-1.2.1.gem \
		xpath-2.0.0.gem \
		yard-0.8.7.6.gem

.include "options.mk"

WRKSRC=		${WRKDIR}
RM_DIR=		share/redmine

USE_TOOLS+=	pax pkg-config

REPLACE_RUBY+=	builder-3.0.4/lib/*
REPLACE_RUBY+=	builder-3.0.4/lib/builder/*
REPLACE_RUBY+=	builder-3.0.4/test/*
REPLACE_RUBY+=	bundler-1.7.10/lib/bundler/templates/*/*/*
REPLACE_RUBY+=	bundler-1.7.10/bin/*
REPLACE_RUBY+=	erubis-2.7.0/benchmark/bench.rb
REPLACE_RUBY+=	ffi-1.9.6/ext/ffi_c/extconf.rb
REPLACE_RUBY+=	rbpdf-1.18.4/test/test_helper.rb
REPLACE_RUBY+=	rmagick-2.13.4/doc/ex/*
REPLACE_RUBY+=	rmagick-2.13.4/examples/*
REPLACE_RUBY+=	rmagick-2.13.4/test/*
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/*
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/*
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/*/*
REPLACE_RUBY+=	ruby-openid-2.3.0/examples/rails_openid/*/*/*
REPLACE_RUBY+=	rubyzip-1.1.6/test/data/*
REPLACE_RUBY+=	redmine-2.6.0/*
REPLACE_RUBY+=	redmine-2.6.0/app/*
REPLACE_RUBY+=	redmine-2.6.0/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	redmine-2.6.0/extra/svn/reposman.rb
REPLACE_RUBY+=	redmine-2.6.0/public/dispatch.fcgi.example
REPLACE_RUBY+=	redmine-2.6.0/script/*
REPLACE_RUBY+=	coderay-1.1.0/bin/coderay
REPLACE_RUBY+=	erubis-2.7.0/bin/*
REPLACE_RUBY+=	erubis-2.7.0/contrib/*
REPLACE_RUBY+=	mocha-1.0.0/bin/build-matrix
REPLACE_RUBY+=	nokogiri-1.6.5/*
REPLACE_RUBY+=	nokogiri-1.6.5/bin/*
REPLACE_RUBY+=	nokogiri-1.6.5/test/*
REPLACE_RUBY+=	rack-1.4.5/bin/*
REPLACE_RUBY+=	rack-1.4.5/test/*
REPLACE_RUBY+=	rack-1.4.5/test/cgi/*
REPLACE_RUBY+=	railties-3.2.19/bin/*
REPLACE_RUBY+=	railties-3.2.19/guides/code/getting_started/*
REPLACE_RUBY+=	railties-3.2.19/guides/code/getting_started/script/*
REPLACE_RUBY+=	railties-3.2.19/lib/rails/generators/rails/app/templates/Rakefile
REPLACE_RUBY+=	railties-3.2.19/lib/rails/generators/rails/plugin_new/templates/Rakefile
REPLACE_RUBY+=	rake-10.4.2/bin/rake
REPLACE_RUBY+=	redcarpet-2.3.0/bin/redcarpet
REPLACE_RUBY+=	rmagick-2.13.4/doc/ex/*
REPLACE_RUBY_DIRS+=	ruby-openid-2.3.0
REPLACE_RUBY+=	rubyzip-1.1.6/*/*
REPLACE_RUBY+=	shoulda-context-1.0.2/bin/*
REPLACE_RUBY+=	sprockets-2.2.3/bin/*
REPLACE_RUBY+=	thor-0.19.1/bin/*
REPLACE_RUBY+=	tilt-1.4.1/bin/*
REPLACE_RUBY+=	treetop-1.4.15/bin/*
REPLACE_RUBY+=	yard-0.8.7.6/bin/*
REPLACE_RUBY+=	pg-0.18.0.pre20141117110243/*
REPLACE_RUBY+=	pg-0.18.0.pre20141117110243/lib/*
REPLACE_RUBY+=	pg-0.18.0.pre20141117110243/lib/pg/*
REPLACE_RUBY+=	pg-0.18.0.pre20141117110243/sample/*
REPLACE_RUBY+=	json-1.8.1/*
REPLACE_RUBY+=	json-1.8.1/tests/*
REPLACE_RUBY+=	json-1.8.1/tools/*
REPLACE_RUBY+=	rdoc-3.12.2/bin/*
REPLACE_RUBY+=	unicorn-4.8.3/*
REPLACE_RUBY+=	unicorn-4.8.3/bin/*
REPLACE_RUBY+=	unicorn-4.8.3/script/*
REPLACE_RUBY+=	unicorn-4.8.3/t/bin/*
REPLACE_RUBY+=	unicorn-4.8.3/test/*
REPLACE_RUBY+=	raindrops-0.13.0/examples/*

CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/bundler-1.7.10/lib/bundler/templates/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/rack-1.4.5/test/cgi/test.ru
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/pg-0.18.0.pre20141117110243/spec/*
CHECK_INTERPRETER_SKIP+=${RM_DIR}/gems/gems/pg-0.18.0.pre20141117110243/spec/pg/*

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

INSTALLATION_DIRS=	share/examples/redmine

EGDIR=		${PREFIX}/share/examples/redmine
CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${PREFIX}/${RM_DIR}/app/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${PREFIX}/${RM_DIR}/app/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${PREFIX}/${RM_DIR}/app/config/additional_environment.rb
CONF_FILES+=	${EGDIR}/unicorn.rb.example \
			${PREFIX}/${RM_DIR}/app/config/unicorn.rb

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RM_DIR=${RM_DIR}

# XXX The following is borrowed from lang/ruby/gem.mk.
# XXX Please integrate the following to lang/ruby/*.mk.
do-extract:
# Extract non-gem tarball
	${RUN} extract_file=${_DISTDIR:Q}/${DISTFILES:M*${EXTRACT_SUFX}:Q}; export extract_file;  \
		cd ${WRKDIR} && cd ${EXTRACT_DIR.${DISTFILES:M*${EXTRACT_SUFX}:Q}} && ${EXTRACT_CMD}
# Extract gems
.for _gem_ in ${DISTFILES:M*.gem}
	${RUN} cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} unpack ${_DISTDIR:Q}/${_gem_:Q}
	${RUN} cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} TZ=UTC ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} spec --ruby ${_DISTDIR:Q}/${_gem_:Q} > ${_gem_}spec
.endfor

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
.if !empty(RUBY_GEMS_VERSION)
_RUBYGEMS_MAJOR=	${RUBY_GEMS_VERSION:C/\.[0-9\.]+$//}
_RUBYGEMS_MINORS=	${RUBY_GEMS_VERSION:C/^([0-9]+)\.*//}
.  if ${_RUBYGEMS_MAJOR} >= 2 && ${_RUBYGEMS_MINORS} >= 2
GEM_EXTSDIR=	${GEM_HOME}/extensions/${RUBY_ARCH}/${RUBY_VERSION}
.  endif
.  if !empty(GEM_EXTSDIR)
PLIST_SUBST+=		GEM_EXTSDIR=${GEM_EXTSDIR}
.  else
PLIST_SUBST+=		GEM_EXTSDIR="@comment "
.  endif
.endif

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
