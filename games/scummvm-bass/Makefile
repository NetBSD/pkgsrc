# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:55 jlam Exp $
#

DISTNAME=		BASS-Floppy
PKGNAME=		scummvm-bass-0
CATEGORIES=		games
MASTER_SITES=		http://www.mixnmojo.com/bss/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
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
