# $NetBSD: Makefile,v 1.38 2025/04/17 21:49:51 wiz Exp $
#
#
# Both of these hashes need to be updated when the solvespace version
# is bumped.
#
# The solvespace hash is used to identify the build version
#
# Solvespace has a private fork of libdxfrw which is stored in github
# as a submodule, which is not included in the v2.3 archive.
#
# [2020-06-06 18:32:46 +0200]
LIBDXF_HASH=		0b7b7b709d9299565db603f878214656ef5e9ddf
# [2022-05-13 17:06:20 -0500] (tag: v3.1)
SOLVESPACE_HASH=	70bde63cb32a7f049fa56cbdf924e2695fcb2916

DISTNAME=		solvespace-3.1
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=solvespace/solvespace/archive/}
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		v${PKGVERSION_NOREV}.tar.gz
DISTFILES+=		${LIBDXF_HASH}.tar.gz
SITES.${LIBDXF_HASH}.tar.gz= \
			${MASTER_SITE_GITHUB:=solvespace/libdxfrw/archive/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.solvespace.com/
COMMENT=		Parametric 2D/3D CAD
LICENSE=		gnu-gpl-v3

EXTRACT_USING=		bsdtar
EXTRACT_DIR.${LIBDXF_HASH}.tar.gz= \
			${WRKSRC}/extlib

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=		-DGIT_COMMIT_HASH=${SOLVESPACE_HASH}

SUBST_CLASSES+=		libdxfrw
SUBST_STAGE.libdxfrw=	pre-configure
SUBST_MESSAGE.libdxfrw=	Set libdxfrw directory
SUBST_FILES.libdxfrw=	CMakeLists.txt
SUBST_SED.libdxfrw=	-e "s,extlib/libdxfrw,extlib/libdxfrw-${LIBDXF_HASH},"

CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		..

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

.include "../../devel/cmake/build.mk"
.include "../../devel/mimalloc/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
