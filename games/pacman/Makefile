# $NetBSD: Makefile,v 1.4 1999/12/17 11:06:48 agc Exp $

DISTNAME=		Pacman-1.0.0
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/clansoft/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

BROKEN=			Problems with ClanLib instance

DEPENDS+=		ClanLib-0.2.2:../../graphics/clanlib

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include
MAKE_ENV+=		LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"
