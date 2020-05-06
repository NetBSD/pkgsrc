# $NetBSD: Makefile,v 1.4 2020/05/06 14:21:39 taca Exp $
#

DISTNAME=	${PLUGIN_NAME}-0.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=haru/}
GITHUB_PROJECT=	${PLUGIN_NAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.r-labs.org/projects/r-labs/wiki/Theme_Changer_en
COMMENT=	Redmine plugin to allow each user to select the theme of Redmine
LICENSE=	gnu-gpl-v2

PLUGIN_NAME=	redmine_theme_changer

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

NO_CONFIGURE=	yes
NO_BUILD=	yes

TC_PLUGIN_DIR=		${REDMINE_PLUGINDIR}/${PLUGIN_NAME}

INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/app/models
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/app/views/my
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/config/locales
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/db/migrate
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/lib
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/test/fixtures
INSTALLATION_DIRS+=	${TC_PLUGIN_DIR}/test/unit

do-install:
	${INSTALL_DATA}	${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}
	${INSTALL_DATA}	${WRKSRC}/app/models/* \
		${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/app/models
	${INSTALL_DATA}	${WRKSRC}/app/views/my/* \
		${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/app/views/my
	${INSTALL_DATA} ${WRKSRC}/config/locales/*.yml \
		 ${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/config/locales
	${INSTALL_DATA} ${WRKSRC}/db/migrate/*.rb \
		${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/db/migrate
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb \
		 ${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/test/test_helper.rb \
		${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/test
	for i in fixtures unit; do \
		${INSTALL_DATA} ${WRKSRC}/test/$$i/* \
			${DESTDIR}${PREFIX}/${TC_PLUGIN_DIR}/test/$$i; \
	done

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
