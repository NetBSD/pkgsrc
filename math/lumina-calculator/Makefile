# $NetBSD: Makefile,v 1.16 2023/11/12 13:22:39 wiz Exp $

DISTNAME=	lumina-calculator-1.6.0
PKGREVISION=	13
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=lumina-desktop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
