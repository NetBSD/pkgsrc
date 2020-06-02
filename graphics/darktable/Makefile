# $NetBSD: Makefile,v 1.115 2020/06/02 08:23:59 adam Exp $

DISTNAME=	darktable-3.0.0
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=darktable-org/}
GITHUB_PROJECT=	darktable
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.darktable.org/
COMMENT=	Photography workflow application
LICENSE=	gnu-gpl-v3

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config bash

#CFLAGS+=	-fopenmp
CFLAGS+=	-Wno-reserved-id-macro

CMAKE_ARGS+=	-DLENSFUN_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include/lensfun
CMAKE_ARGS+=	-DGTHREAD_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DGMODULE_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DUSE_OPENCL=OFF

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=Yes
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DWITH_OPENMP=OFF
CMAKE_ARGS+=	-DUSE_COLORD=OFF

CONFIGURE_DIRS=	../pkgsrc_build
CMAKE_ARG_PATH=	${WRKSRC}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/darktable

# NetBSD 6 libm is the first with exp2f(3)
#NOT_FOR_PLATFORM=	NetBSD-4*-* NetBSD-5.[0-8]*-*

# Hard-coded use of SSE2
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
# SSE alignment issues
GCC_REQD+=	4.2
CFLAGS+=	-mstackrealign -msse2 -march=i686
.endif

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__SUNOS__=1

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
# gdk_pixbuf_new_from_inline
CFLAGS+=	-Wno-error=deprecated-declarations
.endif

CHECK_PORTABILITY_SKIP+=	packaging/macosx/start

pre-configure:
	${MKDIR} ${WRKDIR}/pkgsrc_build

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.14.1nb1

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../devel/libgphoto2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.11
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
PKG_CC=		${PREFIX}/bin/clang
PKG_CXX=	${PREFIX}/bin/clang++
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../net/flickcurl/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
