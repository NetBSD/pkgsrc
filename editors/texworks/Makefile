# $NetBSD: Makefile,v 1.147 2026/09/02 19:01:51 wiz Exp $

DISTNAME=	texworks-0.6.11
PKGREVISION=	2
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

.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
