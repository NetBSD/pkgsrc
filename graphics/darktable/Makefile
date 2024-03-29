# $NetBSD: Makefile,v 1.152 2024/01/30 14:22:07 ryoon Exp $

DISTNAME=	darktable-4.4.2
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=darktable-org/}
GITHUB_PROJECT=	darktable
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.darktable.org/
COMMENT=	Photography workflow application
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config bash:run

# "GNU C++ compiler version 10.4.0 is too old and is unsupported.  Version 12+
# is required"
GCC_REQD+=	12

REPLACE_BASH+=	tools/common.sh
REPLACE_BASH+=	tools/extract_wb_from_images.sh
REPLACE_BASH+=	tools/purge_from_cache.sh
REPLACE_BASH+=	tools/purge_non_existing_images.sh
REPLACE_BASH+=	tools/purge_unused_tags.sh

CFLAGS+=	-Wno-reserved-id-macro

CMAKE_ARGS+=	-DLENSFUN_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include/lensfun
CMAKE_ARGS+=	-DGTHREAD_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DGMODULE_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
# Honour system CFLAGS.
CMAKE_ARGS+=	-DCUSTOM_CFLAGS=ON
CMAKE_ARGS+=	-DUSE_OPENCL=OFF
CMAKE_ARGS+=	-DUSE_OPENMP=OFF

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=Yes
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DUSE_COLORD=OFF
CMAKE_ARGS+=	-DRAWSPEED_ENABLE_WERROR=OFF
CMAKE_ARGS+=	-DTESTBUILD_OPENCL_PROGRAMS=OFF

CONFIGURE_DIRS=	../pkgsrc_build
CMAKE_ARG_PATH=	${WRKSRC}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/darktable

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
# SSE alignment issues
CFLAGS+=	-mstackrealign -msse2 -march=i686
.elif ${MACHINE_ARCH} == "x86_64"
CFLAGS+=	-msse2
.else
CMAKE_ARGS+=	-DBUILD_SSE2_CODEPATHS=OFF
.endif

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__SUNOS__=1

BUILDLINK_TRANSFORM+=	rm:-Werror

CHECK_PORTABILITY_SKIP+=	packaging/macosx/start

pre-configure:
	${MKDIR} ${WRKDIR}/pkgsrc_build

# exiftool presence controls whether a script is installed.  It is
# simplest to just depend, and almost everyone who would used
# darktable would want exiftool anyway.
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.14.1nb1
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
