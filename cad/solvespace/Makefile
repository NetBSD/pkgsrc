# $NetBSD: Makefile,v 1.7 2018/11/12 03:51:46 ryoon Exp $
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
LIBDXF_HASH=		8f958955f54668c142ded760dc951ffd16d9c71b
SOLVESPACE_HASH=	7c1ca460769fc8cbef26d296338d4bbc6f2ef6d0

DISTNAME=		solvespace-2.3
PKGREVISION=		4
CATEGORIES=		cad
MASTER_SITES=		http://github.com/solvespace/solvespace/archive/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		v${PKGVERSION_NOREV}.tar.gz
DISTFILES+=		${LIBDXF_HASH}.tar.gz
SITES.${LIBDXF_HASH}.tar.gz= \
			http://github.com/solvespace/libdxfrw/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.solvespace.com/
COMMENT=		Parametric 2D/3D CAD
LICENSE=		gnu-gpl-v3

EXTRACT_USING=		bsdtar
EXTRACT_DIR.${LIBDXF_HASH}.tar.gz= \
			${WRKSRC}/extlib

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CMAKE=		yes

CMAKE_ARGS+=		-DGIT_COMMIT_HASH=${SOLVESPACE_HASH}

SUBST_CLASSES+=		desktop
SUBST_STAGE.desktop=	pre-configure
SUBST_MESSAGE.desktop=	Fixing absolute path in desktop file
SUBST_FILES.desktop=	src/unix/solvespace.desktop
SUBST_SED.desktop=	-e "s,/usr/bin,${PREFIX}/bin,"

SUBST_CLASSES+=		libdxfrw
SUBST_STAGE.libdxfrw=	pre-configure
SUBST_MESSAGE.libdxfrw=	Set libdxfrw directory
SUBST_FILES.libdxfrw=	CMakeLists.txt
SUBST_SED.libdxfrw=	-e "s,extlib/libdxfrw,extlib/libdxfrw-${LIBDXF_HASH},"

.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
