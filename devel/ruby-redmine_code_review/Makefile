# $NetBSD: Makefile,v 1.2 2017/01/04 23:05:12 rodent Exp $

PLUGIN_NAME=	redmine_code_review
DISTNAME=	0.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${PLUGIN_NAME}-${DISTNAME}
MASTER_SITES=	https://bitbucket.org/haru_iida/${PLUGIN_NAME}/get/
DIST_SUBDIR=	ruby-${PLUGIN_NAME}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.r-labs.org/projects/codereview
COMMENT=	Redmine plugin to annotate source code within the repo browser
LICENSE=	gnu-gpl-v2 AND mit

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

WRKSRC=		${WRKDIR}/haru_iida-${PLUGIN_NAME}-b1e9c70a334d
NO_CONFIGURE=	yes
NO_BUILD=	yes

CODE_REVIEW_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/${PLUGIN_NAME}

INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/app/controllers
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/app/helpers
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/app/models
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/app/views/code_review
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/app/views/code_review_settings
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/images
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/javascripts
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/alert
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/alphacube
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/darkX
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/default
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/iefix
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/lighting
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/mac_os_x
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/mac_os_x_dialog
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/nuncio
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/spread
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/config/locales
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/db/migrate
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/lib
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/test/exemplars
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/test/fixtures
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/test/functional
INSTALLATION_DIRS+=	${CODE_REVIEW_PLUGIN_DIR}/test/unit

do-install:
	${INSTALL_DATA} ${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}
	for i in controllers helpers models; do \
		${INSTALL_DATA} ${WRKSRC}/app/$$i/*.rb \
			${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/app/$$i/; \
	done
	for i in code_review code_review_settings; do \
		${INSTALL_DATA} ${WRKSRC}/app/views/$$i/*.erb \
			${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/app/views/$$i/; \
	done
	for i in images javascripts; do \
		${INSTALL_DATA} ${WRKSRC}/assets/$$i/* \
			${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/assets/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/*.css \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/window_js/*.css \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js
	${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/window_js/behavior.htc \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js
	for i in alert alphacube darkX default iefix lighting mac_os_x \
		mac_os_x_dialog nuncio spread; do \
		${INSTALL_DATA} ${WRKSRC}/assets/stylesheets/window_js/$$i/* \
			${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/assets/stylesheets/window_js/$$i/; \
	done
	${INSTALL_DATA} ${WRKSRC}/config/routes.rb \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/config
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/config/locales
	${INSTALL_DATA} ${WRKSRC}/db/migrate/*.rb \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/db/migrate
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/test/*.rb \
		${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/test
	for i in exemplars fixtures functional unit; do \
		${INSTALL_DATA} ${WRKSRC}/test/$$i/* \
			${DESTDIR}${PREFIX}/${CODE_REVIEW_PLUGIN_DIR}/test/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
