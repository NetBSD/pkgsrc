# $NetBSD: Makefile,v 1.5 2004/01/20 12:18:15 agc Exp $

DISTNAME=	divx-player-installer
PKGNAME=	divxplayer-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME}/}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.divx.com/
COMMENT=	DivX(TM) Video Player for Linux from DivX.com

DEPENDS+=	suse_linux>=7.3:../../emulators/suse_linux
DEPENDS+=	suse_x11>=7.3:../../emulators/suse_linux

ONLY_FOR_PLATFORM= NetBSD-*-i386

WRKSRC=		${WRKDIR}/divx-player-installer
CHECK_SHLIBS=	NO
NO_BUILD=	YES
USE_X11BASE=	YES

DIST_SUBDIR=	${PKGNAME}

BINARY=		divxPlayer.bin
DATADIR=	${PREFIX}/share/divxplayer

post-patch:
	${SED} -e "s|%%DATADIR%%|${DATADIR}|" ${FILESDIR}/launcher.sh \
		> ${WRKDIR}/frontend.sh

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/Skins
	${INSTALL_DATA} ${WRKSRC}/Skins/* ${DATADIR}/Skins
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/frontend.sh \
		${PREFIX}/bin/${BINARY:S/.bin$//}

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
