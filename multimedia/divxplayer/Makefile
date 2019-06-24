# $NetBSD: Makefile,v 1.18 2019/06/24 10:59:41 nia Exp $

DISTNAME=	divx-player-installer
PKGNAME=	divxplayer-0.2.0
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME}/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	https://www.divx.com/
COMMENT=	DivX(TM) Video Player for Linux from DivX.com

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11

NO_BUILD=	yes

BINARY=		divxPlayer.bin
DATADIR=	${PREFIX}/share/divxplayer

INSTALLATION_DIRS=	bin ${DATADIR}/Skins

post-patch:
	${SED} -e "s|%%DATADIR%%|${DATADIR}|" ${FILESDIR}/launcher.sh \
		> ${WRKDIR}/frontend.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/Skins/* ${DESTDIR}${DATADIR}/Skins
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/frontend.sh \
		${DESTDIR}${PREFIX}/bin/${BINARY:S/.bin$//}

.include "../../mk/bsd.pkg.mk"
