# $NetBSD: Makefile,v 1.1 2020/02/13 03:00:16 gutteridge Exp $

DISTNAME=	Arqiver-V0.3.2
PKGNAME=	arqiver-0.3.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://github.com/tsujan/Arqiver/
COMMENT=	Simple Qt5 archive manager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/Arqiver-0.3.2
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
