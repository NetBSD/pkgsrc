# $NetBSD: Makefile,v 1.72 2015/04/19 19:01:26 wiz Exp $

DISTNAME=	Sigil-0.8.6
CATEGORIES=	editors
MASTER_SITES=	-https://github.com/user-none/Sigil/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sigil-ebook.com/
COMMENT=	Multi-platform WYSIWYG ebook editor (for the ePub format)
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=	NO

Qt5_DIR=	${BUILDLINK_PREFIX.qt5-qtbase}/qt5
ALL_ENV+=	Qt5_DIR=${Qt5_DIR}

BUILDLINK_TRANSFORM+=	opt:-O2:-O0
MAKE_ENV+=	CXX_FLAGS="-g"

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

BUILDLINK_TRANSFORM+=	l:BoostParts:boost_date_time:boost_filesystem:boost_regex:boost_system:boost_thread:boost_program_options
BUILDLINK_TRANSFORM+=	l:Xerces:xerces-c
BUILDLINK_TRANSFORM+=	l:zlib:z

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
