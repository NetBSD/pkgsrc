# $NetBSD: Makefile,v 1.16 2002/09/21 13:07:03 jlam Exp $

DISTNAME=		clanbomber-1.01
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/
COMMENT=		Bomberman clone using the ClanLib graphics system

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

pre-configure:
	${ECHO} "#define BOMBERDATDIR \"${PREFIX}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	${ECHO} "#define BOMBERMAPS \"${PREFIX}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

.include "../../graphics/clanlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
