# $NetBSD: Makefile,v 1.51 2026/04/11 17:09:10 wiz Exp $

DISTNAME=	rawtherapee-5.11
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rawtherapee.com/
COMMENT=	Powerful cross-platform raw photo processing program
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
# autoreconf and libtool used by included libraw
USE_TOOLS+=	pkg-config

# for patch-CMakeLists.txt
CMAKE_CONFIGURE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_LIBRAW=ON

.include "../../devel/cmake/build.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libiptcdata/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
