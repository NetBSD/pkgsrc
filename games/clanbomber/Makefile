# $NetBSD: Makefile,v 1.22 2004/10/03 00:14:43 tv Exp $

DISTNAME=		clanbomber-1.01
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/
COMMENT=		Bomberman clone using the ClanLib graphics system

USE_BUILDLINK3=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

pre-configure:
	${ECHO} "#define BOMBERDATDIR \"${PREFIX}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	${ECHO} "#define BOMBERMAPS \"${PREFIX}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../graphics/clanlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
