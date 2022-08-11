# $NetBSD: Makefile,v 1.67 2022/08/11 05:08:20 gutteridge Exp $

DISTNAME=		openmsx-17.0
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_GITHUB:=openMSX/}
GITHUB_PROJECT=		openMSX
GITHUB_TAG=		RELEASE_17_0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://openmsx.org/
COMMENT=		MSX emulator that aims for perfection
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config pax

GCC_REQD+=		8 # std::charconv

# Not sure why this is necessary to find components.hh...
CXXFLAGS+=		-I${WRKSRC}/output

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${WRKSRC}/Contrib/cbios && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/openmsx/machines
	cd ${WRKSRC}/share && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/openmsx
	cd ${WRKSRC}/doc && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/doc/openmsx
# in testing through xfce4-appfinder these icons wouldn't appear...
#.for s in 16 32 48 64 128 256
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
#	${INSTALL_DATA} ${WRKSRC}/share/icons/openMSX-logo-${s}.png \
#		${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/openmsx.png
#.endfor
	${INSTALL_DATA} ${WRKSRC}/share/icons/openMSX-logo-256.png \
		${DESTDIR}${PREFIX}/share/pixmaps/openmsx.png
	${INSTALL_DATA} ${FILESDIR}/openmsx.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${FIND} ${DESTDIR}${PREFIX}/share -name '.gitignore' -exec rm '{}' ';'

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
