# $NetBSD: Makefile,v 1.33.2.1 2012/10/03 12:07:51 spz Exp $
#

DISTNAME=	merkaartor-0.17.2
PKGREVISION=	12
CATEGORIES=	geography
MASTER_SITES=	http://merkaartor.be/attachments/download/253/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.merkaartor.be/
COMMENT=	Merkaartor is an OpenStreetMap mapping program

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS=		PREFIX=${PREFIX} NODEBUG=1 OSMARENDER=1 PROJ=1 GDAL=1 \
			GEOIMAGE=1 GPSDLIB=1 RELEASE=1

SUBST_CLASSES+=			installtarget
SUBST_MESSAGE.installtarget=	Fixing wrong install target
SUBST_STAGE.installtarget=	post-configure
SUBST_FILES.installtarget=	${WRKSRC}/src/Makefile
SUBST_SED.installtarget=	-e 's:--mode=install cp "$$(QMAKE_TARGET)":--mode=install cp "$$(TARGET)":'

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
