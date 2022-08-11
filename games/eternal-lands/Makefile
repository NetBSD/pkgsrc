# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:25 gutteridge Exp $

EL_VER=		1.9.5.8
PKGNAME=	eternal-lands-${EL_VER}
PKGREVISION=	6
CATEGORIES=	games

# latest versions of everything available...

DIST_SUBDIR=	${PKGNAME_NOREV}

DISTFILES+=	Eternal-Lands-${EL_VER}.tar.gz
DISTFILES+=	eternallands-sound_1.9.5.zip
DISTFILES+=	EL_music_full.zip
DISTFILES+=	el_195_p7_data_files.zip

SITES.Eternal-Lands-${EL_VER}.tar.gz=	\
	-https://github.com/raduprv/Eternal-Lands/archive/refs/tags/${EL_VER}.tar.gz

SITES.eternallands-sound_1.9.5.zip=	\
	http://www.gm.fh-koeln.de/~linke/EL-Downloads/

SITES.EL_music_full.zip=	\
	http://www.gm.fh-koeln.de/~linke/EL-Downloads/

EXTRACT_DIR.EL_music_full.zip=	${WRKDIR}/music

SITES.el_195_p7_data_files.zip=	\
	https://github.com/raduprv/Eternal-Lands/releases/download/1.9.5.7/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eternal-lands.com/
COMMENT=	Free 3D fantasy MMORPG
LICENSE=	eternal-lands-license

WRKSRC=		${WRKDIR}/Eternal-Lands-${EL_VER}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config pax
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DEXEC=el

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DEL_BIG_ENDIAN
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec/${PKGBASE}
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
	    ${FILESDIR}/eternal-lands.in > \
	    ${WRKDIR}/eternal-lands.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/eternal-lands.sh \
	    ${DESTDIR}${PREFIX}/bin/eternallands
	${INSTALL_PROGRAM} ${WRKSRC}/el \
	    ${DESTDIR}${PREFIX}/libexec/${PKGBASE}/el
	${INSTALL_DATA} ${WRKSRC}/pkgfiles/eternallands.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pkgfiles/eternallands.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps
	cd ${WRKDIR}/el_data && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/${PKGBASE}
	cd ${WRKDIR}/sound && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/${PKGBASE}/sound
	cd ${WRKDIR}/music && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/${PKGBASE}/music

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
