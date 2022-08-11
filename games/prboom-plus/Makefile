# $NetBSD: Makefile,v 1.12 2022/08/11 05:08:34 gutteridge Exp $

DISTNAME=	prboom-plus-2.6.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=coelckers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coelckers/prboom-plus
COMMENT=	Multiplayer-capable and modified version of DOOM
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/prboom-plus-${PKGVERSION_NOREV}/prboom2

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=	share/doom

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DPRBOOMDATADIR=${PREFIX}/${DOOMWADDIR}
CMAKE_ARGS+=	-DDOOMWADDIR=${PREFIX}/${DOOMWADDIR}
CMAKE_ARGS+=	-DWITH_DUMB=OFF
CMAKE_ARGS+=	-DWITH_FLUIDSYNTH=OFF
CMAKE_ARGS+=	-DWITH_PORTMIDI=OFF

# Process INSTALL.pkgsrc
SUBST_CLASSES+=		install
SUBST_STAGE.install=	do-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_SED.install=	-e 's,DOOMWADDIR,${PREFIX}/${DOOMWADDIR},'

INSTALLATION_DIRS=	share/applications share/icons/hicolor/scalable/apps

pre-configure:
	cd ${WRKSRC}; mkdir build
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ICONS/prboom-plus.desktop \
		${DESTDIR}${PREFIX}/share/applications/prboom-plus.desktop
	${INSTALL_DATA} ${WRKSRC}/ICONS/prboom-plus.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/prboom-plus.svg
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc \
		${DESTDIR}${PREFIX}/share/doc/prboom-plus/INSTALL.pkgsrc

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
