# $NetBSD: Makefile,v 1.5 2020/06/02 08:24:17 adam Exp $
#

PKGREVISION= 3
.include "../../math/xylib/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/convert/g}
COMMENT=	Converter for x-y (powder diffraction) data files
BUILD_TARGET=	gui/xyconvert

DISTINFO_FILE=	../../math/xylib/distinfo
PATCHDIR=	../../math/xylib/patches

GNU_CONFIGURE_WX_VERSION=	no

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gui/xyconvert \
		${DESTDIR}${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
