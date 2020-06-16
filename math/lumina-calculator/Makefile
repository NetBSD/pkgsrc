# $NetBSD: Makefile,v 1.1 2020/06/16 08:18:42 pin Exp $

GITHUB_PROJECT=	lumina-calculator
GITHUB_TAG=	v1.6.0
DISTNAME=	v1.6.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=lumina-desktop/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lumina-desktop/lumina-calculator/
COMMENT=	Scientific calculator from the Lumina desktop
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src-qt5

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

TOOL_DEPENDS+=		qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
