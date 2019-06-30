# $NetBSD: Makefile,v 1.1 2019/06/30 21:56:28 nia Exp $

DISTNAME=	7kaa-music-2.15
CATEGORIES=	games
MASTER_SITES=	https://www.7kfans.com/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.7kfans.com/
COMMENT=	Music files for use with 7KAA
LICENSE=	7kaa-music-license

WRKSRC=		${WRKDIR}/7kaa-music

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/7kaa/MUSIC
INSTALLATION_DIRS+=	share/doc/7kaa

do-install:
	${INSTALL_DATA} ${WRKSRC}/MUSIC/* \
	    ${DESTDIR}${PREFIX}/share/7kaa/MUSIC
	${INSTALL_DATA} ${WRKSRC}/*.txt \
	    ${DESTDIR}${PREFIX}/share/doc/7kaa

.include "../../mk/bsd.pkg.mk"
