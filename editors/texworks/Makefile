# $NetBSD: Makefile,v 1.82 2020/04/12 08:28:36 adam Exp $

DISTNAME=	texworks-0.6.3
PKGREVISION=	5
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
USE_CMAKE=	yes

CMAKE_ARGS+=	-DWITH_LUA:BOOL=OFF
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF
CMAKE_ARGS+=	-DTeXworks_DIC_DIR:PATH=share/hunspell
CMAKE_ARGS+=	-DTeXworks_MAN_DIR:PATH=${PKGMANDIR}/man1

DEPENDS+=	poppler-data>=0.4.5:../../print/poppler-data

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
