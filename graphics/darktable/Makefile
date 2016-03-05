# $NetBSD: Makefile,v 1.59 2016/03/05 11:28:37 jperkin Exp $

DISTNAME=	darktable-1.2.3
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=darktable/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darktable.org/
COMMENT=	Photography workflow application
LICENSE=	gnu-gpl-v3

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config bash

CMAKE_ARGS+=	-DLENSFUN_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include/lensfun
CMAKE_ARGS+=	-DGTHREAD_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DGMODULE_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}/man1
CMAKE_ARGS+=	-DUSE_OPENCL=OFF

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=Yes
CMAKE_ARGS+=	-Wno-dev

SUBST_CLASSES+=		gtkpath
SUBST_FILES.gtkpath=	cmake/modules/FindGTK2.cmake
SUBST_SED.gtkpath=	-e 's|@PREFIX@|${BUILDLINK_PREFIX.gtk2}|'
SUBST_STAGE.gtkpath=	pre-configure
SUBST_MESSAGE.gtkpath=	Setting path to gtk2.

CONFIGURE_DIRS= pkgsrc_build
CMAKE_ARG_PATH= ..
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/darktable

# NetBSD 6 libm is the first with exp2f(3)
#NOT_FOR_PLATFORM= NetBSD-4*-* NetBSD-5.[0-8]*-*

# Hard-coded use of SSE2
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
# SSE alignment issues
GCC_REQD+=	4.2
CFLAGS+=	-mstackrealign -msse2 -march=i686
.endif

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CHECK_PORTABILITY_SKIP+= packaging/macosx/start

pre-configure:
	${MKDIR} ${WRKSRC}/pkgsrc_build

# wants Clearlooks at runtime
DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines

BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.7.14.1nb1

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gegl0.2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../net/flickcurl/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
#.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
