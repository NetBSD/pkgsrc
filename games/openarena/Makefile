# $NetBSD: Makefile,v 1.4 2024/05/11 10:23:23 nia Exp $

DISTNAME=	openarena-0.8.8
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oarena/}
CATEGORIES=	games
EXTRACT_SUFX=	.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.openarena.ws/
COMMENT=	Community-produced deathmatch FPS
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

.include "../../games/ioquake3/arch.mk"

.if ${MACHINE_ARCH} == "earmv6hf"
DEPENDS+=	ioquake3-raspberrypi-[0-9]*:../../games/ioquake3-raspberrypi
IOQ3_BIN=	${PREFIX}/lib/ioquake3/ioquake3.rpi
.else
DEPENDS+=	ioquake3-[0-9]*:../../games/ioquake3
IOQ3_BIN=	${PREFIX}/lib/ioquake3/ioquake3.${QUAKE_ARCH}
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	lib/openarena/baseoa
CHECK_WRKREF_SKIP+=	lib/openarena/baseoa/*.pk3
INSTALLATION_DIRS+=	lib/openarena/missionpack
CHECK_WRKREF_SKIP+=	lib/openarena/missionpack/*.pk3

pre-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
	    -e 's,@IOQ3_BIN@,${IOQ3_BIN},g' \
	    ${FILESDIR}/openarena.in > ${WRKDIR}/openarena.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openarena.sh \
	    ${DESTDIR}${PREFIX}/bin/openarena
	${INSTALL_DATA} ${WRKSRC}/baseoa/*.pk3 \
	    ${DESTDIR}${PREFIX}/lib/openarena/baseoa
	${INSTALL_DATA} ${WRKSRC}/missionpack/*.pk3 \
	    ${DESTDIR}${PREFIX}/lib/openarena/missionpack
	${INSTALL_MAN} ${FILESDIR}/openarena.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${FILESDIR}/openarena.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/openarena.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
