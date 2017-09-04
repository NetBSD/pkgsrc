# $NetBSD: Makefile,v 1.4 2017/09/04 18:08:23 wiz Exp $

DISTNAME=	doom-1.8.wad
PKGNAME=	doom1-1.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/doom/
MASTER_SITES+=	http://www.gamers.org/pub/games/idgames/idstuff/doom/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	https://www.idsoftware.com/archives/doomarc.html
# AWOL
COMMENT=	Shareware levels for Doom

CONFLICTS+=	xdoom<1.10nb4
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/doom
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/doom-1.8.wad \
		${DESTDIR}${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
