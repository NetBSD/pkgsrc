# $NetBSD: Makefile,v 1.26 2013/10/09 17:39:09 wiz Exp $
#

DISTNAME=		TiffIO-120e
PKGNAME=		TiffIO-1.2.0e
PKGREVISION=		13
CATEGORIES=		graphics
MASTER_SITES=		http://artis.imag.fr/Software/TiffIO/SOURCES/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://artis.imag.fr/Software/TiffIO/
COMMENT=		Tiff support for QT image loader

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

PKGSRC_MAKE_ENV+=	QTDIR=${QTDIR:Q} RPM_BUILD_ROOT=${DESTDIR}

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.tiff+=	tiff>=3.8.1
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

do-configure:
	cd ${WRKSRC} && ${SETENV} QTDIR=${QTDIR:Q} ${QTDIR}/bin/qmake \
		CONFIG+=libtiff \
		JPEG=${JPEGBASE}/include \
		TIFF_ROOT=${BUILDLINK_PREFIX.tiff} \
		ZLIB=${BUILDLINK_PREFIX.zlib} TiffIO.pro

.include "../../mk/bsd.pkg.mk"
