# $NetBSD: Makefile,v 1.1 2020/06/14 07:35:58 ryoon Exp $

DISTNAME=	scribus-1.5.6pre20200611
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=scribusproject/}
GITHUB_PROJECT=	scribus
GITHUB_TAG=	37c361f2fcd24dea40c61a7f9638e6248ea3e68a

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.scribus.net/
COMMENT=	Publishing layout with graphical interface (Qt5 port)
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libfreehand/buildlink3.mk"
.include "../../converters/libmspub/buildlink3.mk"
.include "../../converters/libpagemaker/buildlink3.mk"
.include "../../converters/libqxp/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libzmf/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../print/podofo/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
