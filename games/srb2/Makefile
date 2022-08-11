# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:35 gutteridge Exp $

PKGNAME=	srb2-2.2.4
PKGREVISION=	5
CATEGORIES=	games

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.srb2.org/
COMMENT=	Sonic the Hedgehog fan game built using the Doom Legacy engine
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	srb2.tar.gz
DISTFILES+=	srb2-patch.zip
DISTFILES+=	srb2-assets.7z
DISTFILES+=	srb2-assets-opt.7z

SITES.srb2.tar.gz= \
	-https://github.com/STJr/SRB2/archive/SRB2_release_${PKGVERSION_NOREV}.tar.gz

SITES.srb2-patch.zip= \
	-https://github.com/STJr/SRB2/releases/download/SRB2_release_2.2.3/SRB2-v223-patch.zip

SITES.srb2-assets.7z= \
	-https://github.com/mazmazz/SRB2/releases/download/SRB2_assets_220/SRB2-v220-assets.7z

SITES.srb2-assets-opt.7z= \
	-https://github.com/mazmazz/SRB2/releases/download/SRB2_assets_220/SRB2-v220-optional-assets.7z

WRKSRC=		${WRKDIR}/SRB2-SRB2_release_${PKGVERSION_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DGME_INCLUDE_DIR=${BUILDLINK_DIR}/include
CMAKE_ARGS+=	-DSDL2_INCLUDE_DIR=${BUILDLINK_DIR}/include

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm>=1.1:../../devel/nasm
.endif

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting PREFIX search paths.
SUBST_FILES.prefix+=	src/sdl/i_system.c
SUBST_VARS.prefix+=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/srb2

CHECK_PORTABILITY_SKIP+=	libs/miniupnpc/testminiwget.sh

pre-configure:
	${MKDIR} ${WRKSRC}/assets/installer
	${MV} ${WRKDIR}/*.dta ${WRKDIR}/*.pk3 \
	    ${WRKSRC}/assets/installer
	${MV} ${WRKDIR}/2.2.3-patch/*.dta \
	    ${WRKDIR}/2.2.3-patch/*.pk3 \
	    ${WRKSRC}/assets/installer
	${MKDIR} ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/srb2 \
	    ${DESTDIR}${PREFIX}/bin/srb2
	${INSTALL_DATA} ${WRKSRC}/assets/installer/* \
	    ${DESTDIR}${PREFIX}/share/srb2
	${INSTALL_DATA} ${FILESDIR}/srb2.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/srb2.desktop
	${INSTALL_DATA} ${WRKSRC}/srb2.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/srb2.png

.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
