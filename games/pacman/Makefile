# $NetBSD: Makefile,v 1.7 2000/12/15 04:55:25 garbled Exp $

DISTNAME=		Pacman-0.3-CVS-00-11-17
PKGNAME=		Pacman-0.3
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/snapshots/Games/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

DEPENDS+=		ClanLib>=0.2.2:../../graphics/clanlib
DEPENDS+=		autoconf>=2.13:../../devel/autoconf

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${X11BASE}/include
MAKE_ENV+=		LDFLAGS="${LDFLAGS}" CPPFLAGS="${CFLAGS}"

pre-configure:
	cd ${WRKSRC} && autoconf
	${SED} -e 's@/usr/share@${PREFIX}/share@' < ${WRKSRC}/Sources/config.h.in > ${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/Sources/config.h.in

.include "../../mk/bsd.pkg.mk"
