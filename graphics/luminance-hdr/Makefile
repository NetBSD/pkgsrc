# $NetBSD: Makefile,v 1.42 2020/04/12 08:28:50 adam Exp $

DISTNAME=	luminance-hdr-2.4.0
PKGREVISION=	38
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qtpfsgui/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qtpfsgui.sourceforge.net/
COMMENT=	GUI application that aims to provide a workflow for HDR imaging
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
