# $NetBSD: Makefile,v 1.21 2020/06/02 08:24:02 adam Exp $

DISTNAME=	gmic_2.9.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://gmic.eu/files/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmic.eu/
COMMENT=	Full-featured image processing framework
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config bash
MAKE_FLAGS+=	USR=${PREFIX}
MAKE_FLAGS+=	QMAKE=${QTDIR}/bin/qmake
BUILD_TARGET=	cli gimp lib zart

MANCOMPRESSED=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
