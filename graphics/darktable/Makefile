# $NetBSD: Makefile,v 1.4 2011/11/01 06:01:28 sbd Exp $

DISTNAME=	darktable-0.9.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=darktable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://darktable.sourceforge.net/
COMMENT=	Photography workflow application
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config

CMAKE_ARGS+=	-DGTHREAD_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DGMODULE_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.glib2}/include
CMAKE_ARGS+=	-DUSE_OPENMP=OFF
CMAKE_ARGS+=	-DUSE_OPENCL=OFF

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DBINARY_PACKAGE_BUILD=Yes
CMAKE_ARGS+=	-Wno-dev

CONFIGURE_DIRS= pkgsrc_build
CMAKE_ARG_PATH= ..
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/darktable

# NetBSD 6 libm is the first with exp2f(3)
#NOT_FOR_PLATFORM= NetBSD-4*-* NetBSD-5.[0-8]*-*

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
# SSE alignment issues
GCC_REQD=	4.2
CFLAGS+=	-mstackrealign
.endif

# for some reason msgfmt can't handle these two
post-extract:
	${RM} ${WRKSRC}/po/cs.po
	${RM} ${WRKSRC}/po/es.po
	${RM} ${WRKSRC}/po/sv.po

pre-configure:
	${MKDIR} ${WRKSRC}/pkgsrc_build

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../net/flickcurl/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
