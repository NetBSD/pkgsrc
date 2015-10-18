# $NetBSD: Makefile,v 1.56 2015/10/18 15:56:56 adam Exp $

DISTNAME=	hugin-2015.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hugin.sourceforge.net/
COMMENT=	Panorama photo stitcher
LICENSE=	gnu-gpl-v2

DEPENDS+=	enblend-enfuse>=4.0:../../graphics/enblend-enfuse
DEPENDS+=	p5-Image-ExifTool>=8.15:../../graphics/p5-Image-ExifTool

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config

CMAKE_ARGS+=		-DBUILD_HSI=OFF

SUBST_CLASSES+=		apple
SUBST_MESSAGE.apple=	Avoiding Mac OS X application bundles
SUBST_STAGE.apple=	pre-configure
SUBST_FILES.apple=	src/hugin1/hugin/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/ptbatcher/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/icpfind/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/stitch_project/CMakeLists.txt
SUBST_SED.apple=	-e 's,(APPLE),(ELPPA),g'

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../devel/tclap/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/vigra/buildlink3.mk"
#.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
