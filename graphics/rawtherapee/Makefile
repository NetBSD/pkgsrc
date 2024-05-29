# $NetBSD: Makefile,v 1.36 2024/05/29 16:33:02 adam Exp $

DISTNAME=	rawtherapee-5.9
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://rawtherapee.com/shared/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rawtherapee.com/
COMMENT=	Powerful cross-platform raw photo processing program
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# for patch-CMakeLists.txt
CMAKE_ARGS+=	-DPKGMANDIR=${PKGMANDIR}

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libiptcdata/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
