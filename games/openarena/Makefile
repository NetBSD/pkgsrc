# $NetBSD: Makefile,v 1.3 2024/05/07 21:48:54 nia Exp $

#
# There will be warnings about missing dependencies while building.
# In reality, building the "baseoa" mod requires zero dependencies.
#
# Please do not add them.
#

OA_VER=		0.8.8
PKGNAME=	openarena-${OA_VER}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oarena/}
CATEGORIES=	games

# This contains the code for the "baseoa" mod
DISTFILES=	oa-${OA_VER}.tar.bz2

# This contains the pk3 files (graphics, etc)
DISTFILES+=	openarena-${OA_VER}.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.openarena.ws/
COMMENT=	Community-produced deathmatch FPS
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/oa-${OA_VER}

USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	COPYDIR=${DESTDIR}${PREFIX}/lib/openarena

BUILD_TARGET=	release
INSTALL_TARGET=	copyfiles

.include "../../games/ioquake3/arch.mk"

.if ${MACHINE_ARCH} == "earmv6hf"
DEPENDS+=	ioquake3-raspberrypi-[0-9]*:../../games/ioquake3-raspberrypi
IOQ3_BIN=	${PREFIX}/lib/ioquake3/ioquake3.rpi
.else
DEPENDS+=	ioquake3-[0-9]*:../../games/ioquake3
IOQ3_BIN=	${PREFIX}/lib/ioquake3/ioquake3.${QUAKE_ARCH}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}
MAKE_FLAGS+=	COMPILE_ARCH=${QUAKE_ARCH}
CFLAGS+=	-DARCH_STRING="\"${QUAKE_ARCH}\""

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	ARCH=${NATIVE_MACHINE_ARCH}
.endif

# do not use lib64
MAKE_FLAGS.Linux+=	LIB=lib

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	lib/openarena/baseoa
CHECK_WRKREF_SKIP+=	lib/openarena/baseoa/*.pk3
INSTALLATION_DIRS+=	lib/openarena/missionpack
CHECK_WRKREF_SKIP+=	lib/openarena/missionpack/*.pk3

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
	    -e 's,@IOQ3_BIN@,${IOQ3_BIN},g' \
	    ${FILESDIR}/openarena.in > ${WRKDIR}/openarena.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openarena.sh \
	    ${DESTDIR}${PREFIX}/bin/openarena
	${INSTALL_DATA} ${WRKDIR}/openarena-${OA_VER}/baseoa/*.pk3 \
	    ${DESTDIR}${PREFIX}/lib/openarena/baseoa
	${INSTALL_DATA} ${WRKDIR}/openarena-${OA_VER}/missionpack/*.pk3 \
	    ${DESTDIR}${PREFIX}/lib/openarena/missionpack
	${INSTALL_MAN} ${FILESDIR}/openarena.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${FILESDIR}/openarena.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/openarena.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
