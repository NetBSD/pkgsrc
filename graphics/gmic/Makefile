# $NetBSD: Makefile,v 1.58 2024/05/29 16:32:53 adam Exp $

DISTNAME=	gmic_3.2.3
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	https://gmic.eu/files/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmic.eu/
COMMENT=	Full-featured image processing framework
LICENSE=	cecill-2.1 AND cecill-c-v1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config bash
MAKE_FLAGS+=	USR=${PREFIX}
# TODO: make it an option
#MAKE_FLAGS+=	HOST=gimp # default
MAKE_FLAGS+=	HOST=gimp3
MAKE_FLAGS+=	QMAKE=${QTDIR}/bin/qmake
# zart is not in distfile, but would be downloaded with git, so we can't use 'all' target
BUILD_TARGET=	cli lib gmic_qt

MANCOMPRESSED=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/fr/man1

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} share/man/man1/* ${PKGMANDIR}/man1/
	cd ${DESTDIR}${PREFIX} && ${MV} share/man/fr/man1/* ${PKGMANDIR}/fr/man1/

#.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/gimp-devel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
