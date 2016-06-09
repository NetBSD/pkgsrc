# $NetBSD: Makefile,v 1.2 2016/06/09 06:23:40 wiz Exp $
#

GITHUB_TAG=	v0.2.2
DISTNAME=	${GITHUB_TAG}
GITHUB_PROJECT=	redmine_lightbox2
PKGNAME=	${RUBY_PKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S/v//1}
MASTER_SITES=	${MASTER_SITE_GITHUB:=paginagmbh/}
DIST_SUBDIR=	ruby-${GITHUB_PROJECT}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/paginagmbh/redmine_lightbox2
COMMENT=	Lightbox for image attachments in Redmine
LICENSE=	mit

.include "../../meta-pkgs/ruby-redmine-plugins/Makefile.common"

NO_CONFIGURE=	yes
NO_BUILD=	yes

LIGHTBOX2_PLUGIN_DIR=	${REDMINE_PLUGINDIR}/redmine_lightbox2

INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/app/views/attachments
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/assets/images
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/assets/javascripts
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/assets/stylesheets
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/config
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/lib/hooks
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/lib/patches
INSTALLATION_DIRS+=	${LIGHTBOX2_PLUGIN_DIR}/test

do-install:
	${INSTALL_DATA}	${WRKSRC}/init.rb \
		${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}
	${INSTALL_DATA}	${WRKSRC}/app/views/attachments/* \
		${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}/app/views/attachments
	for i in images javascripts stylesheets; do \
		${INSTALL_DATA} ${WRKSRC}/assets/$$i/* \
			${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}/assets/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/config/routes.rb \
		 ${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}/config
	for i in hooks patches; do \
		${INSTALL_DATA} ${WRKSRC}/lib/$$i/* \
			${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}/lib/$$i; \
	done
	${INSTALL_DATA} ${WRKSRC}/test/test_helper.rb \
		 ${DESTDIR}${PREFIX}/${LIGHTBOX2_PLUGIN_DIR}/test

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
