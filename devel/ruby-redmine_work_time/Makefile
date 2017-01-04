# $NetBSD: Makefile,v 1.2 2017/01/04 23:05:13 rodent Exp $
#

PLUGIN_NAME=	redmine_work_time
DISTNAME=	${PLUGIN_NAME}-0.3.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/tkusukawa/${PLUGIN_NAME}/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.r-labs.org/projects/worktime/wiki/WorkTime
COMMENT=	Redmine plugin to view and update Spent time by each user
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

WRKSRC=		${WRKDIR}/${PLUGIN_NAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

WORK_TIME_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/${PLUGIN_NAME}

INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/app/controllers
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/app/helpers
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/app/models
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/app/views/settings
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/app/views/work_time
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/assets/javascripts
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/assets/stylesheets
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/config/locales
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/db/migrate
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/lib
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/test/fixtures
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/test/functional
INSTALLATION_DIRS+=	${WORK_TIME_PLUGIN_DIR}/test/unit

do-install:
	${INSTALL_DATA}	${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}
	for i in controllers helpers models; do \
		${INSTALL_DATA}	${WRKSRC}/app/$$i/*.rb \
			${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/app/$$i; \
	done
	for i in settings work_time; do \
		${INSTALL_DATA}	${WRKSRC}/app/views/$$i/* \
			${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/app/views/$$i; \
	done
	for i in javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/assets/$$i/* \
			${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/assets/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/config/routes.rb \
		 ${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/config
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		 ${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/config/locales
	${INSTALL_DATA} ${WRKSRC}/db/migrate/*.rb \
		 ${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/db/migrate
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb \
		 ${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/test/test_helper.rb \
		 ${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/test
	for i in fixtures functional unit; do \
		${INSTALL_DATA} ${WRKSRC}/test/$$i/* \
			${DESTDIR}${PREFIX}/${WORK_TIME_PLUGIN_DIR}/test/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
