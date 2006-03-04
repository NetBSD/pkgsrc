# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:43 jlam Exp $
#

DISTNAME=		BASS-Floppy
PKGNAME=		scummvm-bass-0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.mixnmojo.com/bss/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scummvm.sourceforge.net/
COMMENT=		Beneath a Steel Sky

WRKSRC=			${WRKDIR}/sky-floppy

BASSDIR=	${PREFIX}/share/games/bass

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s|@BASSDIR@|${BASSDIR}|" <${FILESDIR}/bass.sh \
		>${WRKDIR}/bass.sh

do-install:
	${INSTALL_DATA_DIR} ${BASSDIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${WRKSRC}/sky.dsk ${BASSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/bass.sh ${PREFIX}/bin/bass

.include "../../mk/bsd.pkg.mk"
