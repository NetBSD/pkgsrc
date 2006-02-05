# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:21 joerg Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=  		${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@NetBSD.org
COMMENT=		X windows-based multiplayer combat game (like Midi Maze)

WRKSRC=			${WRKDIR}/netmaze
USE_IMAKE=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|${X11_LDFLAGS}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../mk/bsd.pkg.mk"
