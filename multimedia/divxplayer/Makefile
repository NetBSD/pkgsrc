# $NetBSD: Makefile,v 1.13 2008/03/04 19:32:30 jlam Exp $

DISTNAME=	divx-player-installer
PKGNAME=	divxplayer-0.2.0
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME}/}

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://www.divx.com/
COMMENT=	DivX(TM) Video Player for Linux from DivX.com

DIST_SUBDIR=	${PKGNAME_NOREV}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/divx-player-installer
BUILD_DIRS=	# empty

BINARY=		divxPlayer.bin
DATADIR=	${PREFIX}/share/divxplayer

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e "s|%%DATADIR%%|${DATADIR}|" ${FILESDIR}/launcher.sh \
		> ${WRKDIR}/frontend.sh

do-install:
	${MKDIR} ${DESTDIR}${DATADIR}
	${MKDIR} ${DESTDIR}${DATADIR}/Skins
	${INSTALL_DATA} ${WRKSRC}/Skins/* ${DESTDIR}${DATADIR}/Skins
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/frontend.sh \
		${DESTDIR}${PREFIX}/bin/${BINARY:S/.bin$//}

.include "../../mk/bsd.pkg.mk"
