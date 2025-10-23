# $NetBSD: Makefile,v 1.50 2025/10/23 20:37:17 wiz Exp $

PKGVERSION=	1.2.1
PKGNAME=	widelands-${PKGVERSION}
PKGREVISION=	3
DISTNAME=	v${PKGVERSION:C/rc/-rc/}
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/wl/widelands/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.widelands.org/
COMMENT=	Fantasy real-time strategy game inspired by Settlers II
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_BASEDIR=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_DATADIR=${PREFIX}/share/widelands
CMAKE_CONFIGURE_ARGS+=	-DWL_INSTALL_BINDIR=${PREFIX}/bin
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INCLUDE_PATH=${PREFIX}/include/boost

BUILDLINK_TRANSFORM+=	rm:-Werror=shadow

# too much spam from boost headers
BUILDLINK_TRANSFORM+=	rm:-Wold-style-cast
BUILDLINK_TRANSFORM+=	rm:-Wundef

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/widelands

DIST_SUBDIR=	widelands
WRKSRC=		${WRKDIR}/widelands

.include "../../mk/bsd.prefs.mk"

# XXX: The following trick might not work everywhere!
#      Some systems, like Darwin, do not provide pgettext(),
#      and devel/gettext-lib does not provide it either.
pre-configure:
.if ${OPSYS} != "Darwin"
	${PRINTF} '#include <libintl.h>\n' > ${WRKSRC}/src/third_party/gettext/gettext.h
.endif
	${MKDIR} ${WRKSRC}/build

post-install:
	${MV}	${DESTDIR}${PREFIX}/VERSION \
		${DESTDIR}${PREFIX}/ChangeLog \
		${DESTDIR}${PREFIX}/CREDITS \
		${DESTDIR}${PREFIX}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/widelands

.include "../../archivers/minizip/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/asio/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
