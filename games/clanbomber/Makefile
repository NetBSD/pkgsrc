# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 07:42:32 garbled Exp $

DISTNAME=		clanbomber-1.01
CATEGORIES=		games x11
MASTER_SITES=		http://www.clanbomber.de/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanbomber.de/

DEPENDS+=		ClanLib>=0.4:../../graphics/clanlib

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include
MAKE_ENV+=		LDFLAGS="${LDFLAGS}" CPPFLAGS="${CFLAGS}"

pre-configure:
	echo "#define BOMBERDATDIR \"${X11BASE}/share/clanbomber/clanbomber.dat\"" >> ${WRKSRC}/config.h.in
	echo "#define BOMBERMAPS \"${X11BASE}/share/clanbomber/maps\"" >> ${WRKSRC}/config.h.in

.include "../../mk/bsd.pkg.mk"
