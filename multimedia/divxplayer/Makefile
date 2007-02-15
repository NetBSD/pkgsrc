# $NetBSD: Makefile,v 1.11 2007/02/15 22:22:19 joerg Exp $

DISTNAME=	divx-player-installer
PKGNAME=	divxplayer-0.2.0
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME}/}

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://www.divx.com/
COMMENT=	DivX(TM) Video Player for Linux from DivX.com

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_x11>=7.3:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

ONLY_FOR_PLATFORM= *-*-i386

WRKSRC=		${WRKDIR}/divx-player-installer
NO_BUILD=	YES
USE_X11BASE=	YES

DIST_SUBDIR=	${PKGNAME_NOREV}

BINARY=		divxPlayer.bin
DATADIR=	${PREFIX}/share/divxplayer

INSTALLATION_DIRS=	bin

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

.include "../../mk/bsd.pkg.mk"
