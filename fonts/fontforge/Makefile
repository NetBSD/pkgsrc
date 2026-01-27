# $NetBSD: Makefile,v 1.163 2026/01/27 08:39:27 wiz Exp $

DISTNAME=	fontforge-20251009
PKGREVISION=	3
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	fontforge
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fontforge.github.io/
COMMENT=	Postscript font editor
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++11

# -- Configuring done (15.4s)
# CMake Error in Unicode/CMakeLists.txt:
#   Target "gunicode" requires the language dialect "C17" (with compiler
#   extensions).  But the current compiler "GNU" does not support this, or
#   CMake does not know the flags to enable it.
USE_CC_FEATURES=	c17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config xgettext
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOCS=NO
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=		test

PY_PATCHPLIST=		yes

CHECK_PORTABILITY_SKIP+=	osx/FontForge.app/Contents/MacOS/*

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libspiro/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libuninameslist/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
