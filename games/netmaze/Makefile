# $NetBSD: Makefile,v 1.3 2003/02/26 04:07:48 jschauma Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=  		${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@netbsd.org
COMMENT=		X windows-based multiplayer combat game (like Midi Maze)

USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/netmaze

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|-Wl,-R${X11BASE}/lib|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../mk/bsd.pkg.mk"
