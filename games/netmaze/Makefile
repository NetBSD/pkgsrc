# $NetBSD: Makefile,v 1.15 2013/03/25 01:59:03 dholland Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@NetBSD.org
COMMENT=		X windows-based multiplayer combat game (like Midi Maze)

WRKSRC=			${WRKDIR}/netmaze
USE_IMAKE=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|${X11_LDFLAGS}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
