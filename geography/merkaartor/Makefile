# $NetBSD: Makefile,v 1.85 2020/06/06 04:01:15 rillig Exp $

DISTNAME=	merkaartor-0.17.2
PKGREVISION=	56
CATEGORIES=	geography
MASTER_SITES=	http://merkaartor.be/attachments/download/253/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merkaartor.be/
COMMENT=	OpenStreetMap mapping program

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS=		PREFIX=${PREFIX} NODEBUG=1 OSMARENDER=1 PROJ=1 GDAL=1 \
			GEOIMAGE=1 GPSDLIB=1 RELEASE=1

INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
		${QTDIR}/bin/lrelease src/src.pro
	cd ${WRKSRC} && \
		${QMAKE} ${CONFIGURE_ARGS} Merkaartor.pro && \
		${MAKE} qmake

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
