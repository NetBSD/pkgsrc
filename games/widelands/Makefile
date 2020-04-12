# $NetBSD: Makefile,v 1.9 2020/04/12 08:28:46 adam Exp $

DISTNAME=	widelands-build20
PKGNAME=	widelands-20
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://launchpad.net/widelands/build${PKGVERSION_NOREV}/build${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.widelands.org/
COMMENT=	Fantasy real-time strategy game inspired by Settlers II
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.8

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DWL_INSTALL_BASEDIR=${PREFIX}
CMAKE_ARGS+=	-DWL_INSTALL_DATADIR=${PREFIX}/share/widelands

BUILDLINK_TRANSFORM+=	rm:-Werror=shadow

# too much spam from boost headers
BUILDLINK_TRANSFORM+=	rm:-Wold-style-cast
BUILDLINK_TRANSFORM+=	rm:-Wundef

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/widelands

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
	${MV}	${DESTDIR}${PREFIX}/widelands \
		${DESTDIR}${PREFIX}/wl_map_object_info \
		${DESTDIR}${PREFIX}/wl_map_info \
		${DESTDIR}${PREFIX}/bin
	${MV}	${DESTDIR}${PREFIX}/VERSION \
		${DESTDIR}${PREFIX}/ChangeLog \
		${DESTDIR}${PREFIX}/CREDITS \
		${DESTDIR}${PREFIX}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/widelands

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
