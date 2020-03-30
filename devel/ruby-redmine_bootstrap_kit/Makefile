# $NetBSD: Makefile,v 1.6 2020/03/30 10:24:33 taca Exp $

GITHUB_PROJECT=	redmine_bootstrap_kit
DISTNAME=	0.2.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbox-web/}
DIST_SUBDIR=	ruby-${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbox-web/redmine_bootstrap_kit
COMMENT=	Redmine plugin which facilitates developing Redmine plugins
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

.undef		MESSAGE_SRC

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_TOOLS+=	pax

DISTFILES+=	${DEFAULT_DISTFILES}
GEMS_DISTFILES=	will_paginate-3.1.5.gem

DISTFILES+=			${GEMS_DISTFILES}
SITES.will_paginate-3.1.5.gem=	https://rubygems.org/downloads/

GEM_EXTSDIR_NEEDS_SUBDIR=	no

.include "../../lang/ruby/gem-extract.mk"

RM_BSK_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/${GITHUB_PROJECT}

REPLACE_RUBY+=		${WRKDIR}/will_paginate-3.1.5/spec/console

INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/bootstrap
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/code_mirror
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/high_charts
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/jquery_file_tree
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/redmine_bootstrap_kit
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/helpers/zero_clipboard
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/app/views/common
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/fonts
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/images/jquery_file_tree

INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/bootstrap
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/comment
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/display
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/edit
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/runmode
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/selection
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/keymap
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/nginx
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/php
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/python
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/ruby
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/yaml
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/highcharts/modules
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/jquery_file_tree
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/javascripts/zero_clipboard
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/stylesheets/bootstrap/images
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/stylesheets/codemirror/addon/display
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/stylesheets/jquery_file_tree
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/assets/stylesheets/zero_clipboard
INSTALLATION_DIRS+=	${RM_BSK_PLUGIN_DIR}/config/locales

do-build:
.for _gem_ in ${DISTFILES:M*.gem:S/.gem$//g}
	${RUN} cd ${WRKDIR}/${_gem_} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} build ../${_gem_}.gemspec
	${RUN} ${TEST} -f ${WRKDIR}/${_gem_}/${_gem_}.gem || \
		${FAIL_MSG} "Build of ${_gem_}.gem failed."
.endfor

RUBYGEM_INSTALL_ROOT=		${WRKDIR}/.inst
RUBYGEM_INSTALL_ROOT_OPTION=	--install-root ${RUBYGEM_INSTALL_ROOT}
_RUBYGEM_OPTIONS=		--no-update-sources # don't cache the gem index
_RUBYGEM_OPTIONS+=		--install-dir ${PREFIX}/${GEM_HOME}
_RUBYGEM_OPTIONS+=		${RUBYGEM_INSTALL_ROOT_OPTION}
_RUBYGEM_OPTIONS+=		--ignore-dependencies --no-document

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

# Install Redmine Bootstrap Kit plugin
	${INSTALL_DATA} ${WRKSRC}/Gemfile ${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}
	${INSTALL_DATA}	${WRKSRC}/app/helpers/*.rb \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/app/helpers
	for i in bootstrap code_mirror high_charts jquery_file_tree \
		redmine_bootstrap_kit zero_clipboard ; do \
		${INSTALL_DATA} ${WRKSRC}/app/helpers/$$i/*.rb \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/app/helpers/$$i; \
	done
	${INSTALL_DATA}	${WRKSRC}/app/views/common/* \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/app/views/common
	for i in fonts images stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/assets/$$i/*.* \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/assets/images/jquery_file_tree/*.* \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/images/jquery_file_tree
	for i in bootstrap codemirror highcharts jquery_file_tree \
		zero_clipboard ; do \
		${INSTALL_DATA} ${WRKSRC}/assets/javascripts/$$i/*.* \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/javascripts/$$i; \
	done
	for i in comment display edit runmode selection; do \
		${INSTALL_DATA} ${WRKSRC}/assets/javascripts/codemirror/addon/$$i/*.js \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/addon/$$i; \
	done
	for i in keymap mode ; do \
		${INSTALL_DATA} ${WRKSRC}/assets/javascripts/codemirror/$$i/*.js \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/$$i; \
	done
	for i in nginx php python ruby yaml ; do \
		 ${INSTALL_DATA} ${WRKSRC}/assets/javascripts/codemirror/mode/$$i/* \
			 ${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/javascripts/codemirror/mode/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/assets/javascripts/highcharts/modules/*.js \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/javascripts/highcharts/modules
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/*.css \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/stylesheets
	for i in bootstrap codemirror jquery_file_tree zero_clipboard ; do \
		${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/$$i/*.css \
			${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/stylesheets/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/bootstrap/images/*.png \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/stylesheets/bootstrap/images
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/codemirror/addon/display/*.css \
		${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/assets/stylesheets/codemirror/addon/display
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		 ${DESTDIR}${PREFIX}/${RM_BSK_PLUGIN_DIR}/config/locales

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
