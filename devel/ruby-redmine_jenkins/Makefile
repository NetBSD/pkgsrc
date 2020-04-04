# $NetBSD: Makefile,v 1.6 2020/04/04 04:02:11 mef Exp $

GITHUB_PROJECT=	redmine_jenkins
DISTNAME=	1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbox-web/}
DIST_SUBDIR=	ruby-${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbox-web/redmine_jenkins
COMMENT=	Plugin allows management of Jenkins projects within Redmine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-redmine_bootstrap_kit-[0-9]*:../../devel/ruby-redmine_bootstrap_kit

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

DISTFILES+=		${DEFAULT_DISTFILES}
GEMS_DISTFILES=		haml-4.0.6.gem haml-rails-0.9.0.gem html2haml-2.0.0.gem
GEMS_DISTFILES+=	jenkins_api_client-1.3.0.gem mixlib-shellout-2.0.1.gem
GEMS_DISTFILES+=	ruby_parser-3.6.6.gem sexp_processor-4.5.1.gem
GEMS_DISTFILES+=	terminal-table-1.4.5.gem

DISTFILES+=	${GEMS_DISTFILES}
.for _gem_ in ${GEMS_DISTFILES}
DISTFILES+=	${_gem_}
SITES.${_gem_}=	https://rubygems.org/downloads/
.endfor

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_TOOLS+=	bash:run pax

GEM_EXTSDIR_NEEDS_SUBDIR=	no
.include "../../lang/ruby/gem-extract.mk"

JENKINS_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/redmine_jenkins

REPLACE_BASH+=	${WRKDIR}/jenkins_api_client-1.3.0/travis/setup.sh
REPLACE_BASH+=	${WRKDIR}/jenkins_api_client-1.3.0/travis/setup_crumb.sh

REPLACE_RUBY+=	${WRKDIR}/haml-4.0.6/bin/haml
REPLACE_RUBY+=	${WRKDIR}/html2haml-2.0.0/bin/html2haml
REPLACE_RUBY+=	${WRKDIR}/jenkins_api_client-1.3.0/bin/jenkinscli
REPLACE_RUBY+=	${WRKDIR}/jenkins_api_client-1.3.0/scripts/login_with_pry.rb
REPLACE_RUBY+=	${WRKDIR}/ruby_parser-3.6.6/bin/ruby_parse
REPLACE_RUBY+=	${WRKDIR}/ruby_parser-3.6.6/bin/ruby_parse_extract_error

INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/controllers
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/helpers
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/models
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/presenters
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/services
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/use_cases/jenkins_jobs
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/views/common
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/views/jenkins
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/views/jenkins_jobs
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/views/jenkins_settings
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/app/views/projects/settings
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/assets/images
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/assets/stylesheets
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/config/locales
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/db/migrate
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/lib/redmine_jenkins/hooks
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/lib/redmine_jenkins/patches
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/lib/tasks
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/spec/factories
INSTALLATION_DIRS+=	${JENKINS_PLUGIN_DIR}/spec/models

do-build:
.for _gem_ in ${DISTFILES:M*.gem:S/.gem$//g}
	${RUN} cd ${WRKDIR}/${_gem_} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM_NAME} build ../${_gem_}.gemspec
	${RUN} ${TEST} -f ${WRKDIR}/${_gem_}/${_gem_}.gem || \
	${FAIL_MSG} "Build of ${_gem_}.gem failed."
.endfor

RUBYGEM_INSTALL_ROOT=		${WRKDIR}/.inst
RUBYGEM_INSTALL_ROOT_OPTION=	--install-root ${RUBYGEM_INSTALL_ROOT}
_RUBYGEM_OPTIONS=		--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=		--install-dir ${PREFIX}/${GEM_HOME}
_RUBYGEM_OPTIONS+=		${RUBYGEM_INSTALL_ROOT_OPTION}
_RUBYGEM_OPTIONS+=		--ignore-dependencies
_RUBYGEM_OPTIONS+=		--no-document

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
# Install Redmine Jenkins
	${INSTALL_DATA}	${WRKSRC}/Gemfile ${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}
	for i in controllers helpers models presenters services; do \
		${INSTALL_DATA}	${WRKSRC}/app/$$i/*.rb \
			${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/app/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/app/use_cases/jenkins_jobs/*.rb \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/app/use_cases/jenkins_jobs
	for i in common jenkins jenkins_jobs jenkins_settings ; do \
		${INSTALL_DATA}	${WRKSRC}/app/views/$$i/* \
			${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/app/views/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/app/views/projects/settings/* \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/app/views/projects/settings
	for i in images stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/assets/$$i/* \
			${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/assets/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/config/routes.rb \
		 ${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/config
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		 ${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/config/locales
	${INSTALL_DATA} ${WRKSRC}/db/migrate/*.rb \
		 ${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/db/migrate
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/redmine_jenkins/*.rb \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/lib/redmine_jenkins
	for i in hooks patches; do \
		${INSTALL_DATA} ${WRKSRC}/lib/redmine_jenkins/$$i/*.* \
			${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/lib/redmine_jenkins/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/lib/tasks/* \
		${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/lib/tasks
	${INSTALL_DATA} ${WRKSRC}/spec/*.* \
		 ${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/spec
	for i in factories models; do \
		${INSTALL_DATA} ${WRKSRC}/spec/$$i/* \
			${DESTDIR}${PREFIX}/${JENKINS_PLUGIN_DIR}/spec/$$i; \
	done

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${GEM_HOME}/gems/haml-4.0.6/lib/haml/*.rb
	${CHMOD} -x ${DESTDIR}${PREFIX}/${GEM_HOME}/gems/ruby_parser-3.6.6/test/*.rb
	${CHMOD} -x ${DESTDIR}${PREFIX}/${GEM_HOME}/gems/sexp_processor-4.5.1/test/*.rb

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
