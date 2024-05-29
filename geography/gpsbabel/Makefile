# $NetBSD: Makefile,v 1.56 2024/05/29 16:32:46 adam Exp $
#

GITHUB_PROJECT=	gpsbabel
VERSION=	1.8.0
GH_VERSION=	1_8_0
GITHUB_TAG=	refs/tags/gpsbabel_${GH_VERSION}
DISTNAME=	gpsbabel_${GH_VERSION}
PKGNAME=	gpsbabel-${VERSION}
PKGREVISION=	13
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=GPSBabel/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gpsbabel.org/
#HOMEPAGE=	https://github.com/gpsbabel/gpsbabel
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_LANGUAGES+=	c c++11
USE_TOOLS+=	pkg-config
QMAKE=		${QTDIR}/bin/qmake
QMAKE_ARGS+=	WITH_LIBUSB=no
QMAKE_ARGS+=	WITH_LIBUSB=pkgconfig
QMAKE_ARGS+=	WITH_ZLIB=pkgconfig

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKE_ARGS} GPSBabel.pro

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL} ${WRKSRC}/gpsbabel ${DESTDIR}${PREFIX}/bin

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
