# $NetBSD: Makefile,v 1.1.1.1 1999/07/21 22:58:26 garbled Exp $

DISTNAME=		Pacman-1.0.0
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/clansoft/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

DEPENDS+=		ClanLib-0.1.15:../../graphics/ClanLib

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include
MAKE_ENV+=		LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
