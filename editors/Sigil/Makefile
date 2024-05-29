# $NetBSD: Makefile,v 1.174 2024/05/29 16:32:21 adam Exp $

DISTNAME=	Sigil-2.0.2
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sigil-Ebook/}
GITHUB_PROJECT=	Sigil
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sigil-ebook.com/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

Qt5_DIR=	${BUILDLINK_PREFIX.qt5-qtbase}/qt5
ALL_ENV+=	Qt5_DIR=${Qt5_DIR}

USE_LANGUAGES=	c c++0x
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DUSE_SYSTEM_LIBS=ON
# upstream defaults to Qt6, but this needs the unpackaged qt6-webengine
CMAKE_ARGS+=	-DUSE_QT5=1
CMAKE_ARGS+=	-DPYTHON_LIBRARY=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so
CMAKE_ARGS+=	-DPYTHON_INCLUDE_DIR=${PREFIX}/include/python${PYVERSSUFFIX}

BUILDLINK_TRANSFORM+=	l:BoostParts:boost_date_time:boost_filesystem:boost_regex:boost_system:boost_thread:boost_program_options
BUILDLINK_TRANSFORM+=	l:Xerces:xerces-c
BUILDLINK_TRANSFORM+=	l:zlib:z

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/sigil
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		src/Resource_Files/*/*/*/*.py
REPLACE_PYTHON+=		src/Resource_Files/*/*/*.py
REPLACE_PYTHON+=		src/Resource_Files/*/*.py

.include "../../devel/cmake/build.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
