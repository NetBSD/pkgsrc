# $NetBSD: Makefile,v 1.5 2003/03/29 12:41:07 jmmv Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
PKGREVISION=		1
WRKSRC=			${WRKDIR}/netmaze
CATEGORIES=		games
MASTER_SITES=  		${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@netbsd.org
COMMENT=		X windows-based multiplayer combat game (like Midi Maze)

USE_IMAKE=		yes

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|${X11_LDFLAGS}|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../mk/bsd.pkg.mk"
