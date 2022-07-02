# $NetBSD: Makefile,v 1.67 2022/07/02 16:53:24 ryoon Exp $

DISTNAME=	luminance-hdr-2.6.0
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qtpfsgui/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qtpfsgui.sourceforge.net/
COMMENT=	GUI application that aims to provide a workflow for HDR imaging
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
CMAKE_ARGS+=	-DQt5WebEngineCore_FOUND=FALSE
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
