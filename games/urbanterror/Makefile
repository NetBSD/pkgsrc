# $NetBSD: Makefile,v 1.1 2024/05/07 15:13:43 nia Exp $

DISTNAME=	UrbanTerror434_full
PKGNAME=	urbanterror-4.3.4
CATEGORIES=	games
MASTER_SITES=	http://cdn.urbanterror.info/urt/43/releases/zips/
EXTRACT_SUFX=	.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.urbanterror.info/home/
COMMENT=	Hollywood tactical shooter based on the ioquake3 engine
#LICENSE=	# freeware

WRKSRC=		${WRKDIR}/UrbanTerror43

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
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
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

INSTALLATION_DIRS+=	lib/ioquake3/q3ut4
CHECK_WRKREF_SKIP+=	lib/ioquake3/q3ut4/*

pre-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
	    -e 's,@IOQ3_BIN@,${IOQ3_BIN},g' \
	    ${FILESDIR}/urbanterror.sh > ${WRKDIR}/urbanterror.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/urbanterror.sh \
	    ${DESTDIR}${PREFIX}/bin/urbanterror
	${INSTALL_SCRIPT} ${FILESDIR}/urbanterror.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${FILESDIR}/urbanterror.xpm \
	    ${DESTDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/q3ut4 && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/lib/ioquake3/q3ut4

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
