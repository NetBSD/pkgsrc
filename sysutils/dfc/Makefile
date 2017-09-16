# $NetBSD: Makefile,v 1.1 2017/09/16 09:30:26 wiz Exp $

DISTNAME=	dfc-3.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.gw-computing.net/attachments/download/615/
# Note: the number at the end of the URL above changes for each release

MAINTAINER=	mcy@lm7.fr
HOMEPAGE=	http://projects.gw-computing.net/projects/dfc
COMMENT=	Display file system space usage using graph and colors
LICENSE=	modified-bsd

USE_CMAKE=	yes
CMAKE_ARGS+=	-DMAN_PATH=${PREFIX}/${PKGMANDIR}

EGDIR=			${PREFIX}/share/examples/dfc
INSTALLATION_DIRS=	${EGDIR}
MAKE_DIRS=		${PKG_SYSCONFDIR}/xdg
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/dfc
CONF_FILES=		${EGDIR}/dfcrc ${PKG_SYSCONFDIR}/xdg/dfc/dfcrc
USE_PKGLOCALEDIR=       yes
CMAKE_ARGS+=		-DNLS_ENABLED=true

post-install:
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/dfc/dfcrc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/dfc/fr/dfcrc ${DESTDIR}${EGDIR}/dfcrc.fr
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/dfc/nl/dfcrc ${DESTDIR}${EGDIR}/dfcrc.nl

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
