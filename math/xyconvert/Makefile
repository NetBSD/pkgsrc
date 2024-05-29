# $NetBSD: Makefile,v 1.27 2024/05/29 16:33:29 adam Exp $

.include "../../math/xylib/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/convert/g}
PKGREVISION=	9
COMMENT=	Converter for x-y (powder diffraction) data files
BUILD_TARGET=	gui/xyconvert

DISTINFO_FILE=	../../math/xylib/distinfo
PATCHDIR=	../../math/xylib/patches

USE_LANGUAGES+=	c++11

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gui/xyconvert \
		${DESTDIR}${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
