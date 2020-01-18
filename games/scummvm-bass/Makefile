# $NetBSD: Makefile,v 1.9 2020/01/18 23:32:05 rillig Exp $
#

DISTNAME=		BASS-Floppy
PKGNAME=		scummvm-bass-0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.mixnmojo.com/bss/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://scummvm.sourceforge.net/
COMMENT=		Beneath a Steel Sky

WRKSRC=			${WRKDIR}/sky-floppy

BASSDIR=	${PREFIX}/share/games/bass

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s|@BASSDIR@|${BASSDIR}|" <${FILESDIR}/bass.sh \
		>${WRKDIR}/bass.sh

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BASSDIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${WRKSRC}/sky.dsk ${DESTDIR}${BASSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bass.sh ${DESTDIR}${PREFIX}/bin/bass

.include "../../mk/bsd.pkg.mk"
