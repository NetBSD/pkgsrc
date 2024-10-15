# $NetBSD: Makefile,v 1.128 2024/10/15 16:15:33 adam Exp $

DISTNAME=	texworks-0.6.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=TeXworks/}
GITHUB_PROJECT=	texworks
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.tug.org/texworks/
COMMENT=	Simple TeX front-end program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DWITH_LUA:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_PYTHON:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DTeXworks_DIC_DIR:PATH=share/hunspell
CMAKE_CONFIGURE_ARGS+=	-DTeXworks_MAN_DIR:PATH=${PKGMANDIR}/man1
CMAKE_CONFIGURE_ARGS+=	-DTW_BUILD_ID='pkgsrc'

DEPENDS+=	poppler-data>=0.4.5:../../print/poppler-data

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
