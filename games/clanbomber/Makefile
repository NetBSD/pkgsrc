# $NetBSD: Makefile,v 1.15 2002/03/30 02:58:47 hubertf Exp $

DISTNAME=		clanbomber-1.01
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/
COMMENT=		Bomberman clone using the ClanLib graphics system

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

pre-configure:
	${ECHO} "#define BOMBERDATDIR \"${X11PREFIX}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	${ECHO} "#define BOMBERMAPS \"${X11PREFIX}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

.include "../../graphics/clanlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
