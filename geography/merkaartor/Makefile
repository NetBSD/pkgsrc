# $NetBSD: Makefile,v 1.1.1.1 2009/06/04 10:57:59 drochner Exp $
#

DISTNAME=	merkaartor-0.13.2
CATEGORIES=	geography
MASTER_SITES=	http://www.merkaartor.org/downloads/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.merkaartor.org/
COMMENT=	Merkaartor is an openstreetmap mapping program

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS=		PREFIX=${PREFIX} NODEBUG=1 OSMARENDER=1 PROJ=1 GDAL=1 \
			GEOIMAGE=1 GPSD=1

SUBST_CLASSES+=		libxml2
SUBST_MESSAGE.libxml2=	Fixing hardcoded path: libxml2
SUBST_STAGE.libxml2=	post-configure
SUBST_FILES.libxml2=	${WRKSRC}/Makefile
SUBST_SED.libxml2=	-e "s:/usr/include/libxml2:${BUILDLINK_PREFIX.libxml2}/include/libxml2:g"

SUBST_CLASSES+=			installtarget
SUBST_MESSAGE.installtarget=	Fixing wrong install target
SUBST_STAGE.installtarget=	post-configure
SUBST_FILES.installtarget=	${WRKSRC}/Makefile
SUBST_SED.installtarget=	-e 's:--mode=install cp "$$(QMAKE_TARGET)":--mode=install cp "$$(TARGET)":'

do-configure:
	cd ${WRKSRC} && \
		${QTDIR}/bin/lrelease Merkaartor.pro
	cd ${WRKSRC} && \
		${QMAKE} ${CONFIGURE_ARGS} Merkaartor.pro

.include "../../misc/proj/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
