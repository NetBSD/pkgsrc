# $NetBSD: Makefile,v 1.77 2016/03/02 23:08:22 ryoon Exp $

DISTNAME=	Sigil-0.9.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sigil-Ebook/}
GITHUB_PROJECT=	Sigil
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sigil-ebook.com/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

#MAKE_JOBS_SAFE=	NO

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-cssutils-[0-9]*:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

Qt5_DIR=	${BUILDLINK_PREFIX.qt5-qtbase}/qt5
ALL_ENV+=	Qt5_DIR=${Qt5_DIR}

BUILDLINK_TRANSFORM+=	opt:-O2:-O0
#MAKE_ENV+=	CXX_FLAGS="-g"

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

BUILDLINK_TRANSFORM+=	l:BoostParts:boost_date_time:boost_filesystem:boost_regex:boost_system:boost_thread:boost_program_options
BUILDLINK_TRANSFORM+=	l:Xerces:xerces-c
BUILDLINK_TRANSFORM+=	l:zlib:z

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/sigil
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=	src/Sigil/Resource_Files/plugin_launchers/python/*.py

.include "../../mk/compiler.mk"
# GCC 4.4 and above needs this
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++0x
CWRAPPERS_APPEND.cxx+=	-std=c++0x
.endif

.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
