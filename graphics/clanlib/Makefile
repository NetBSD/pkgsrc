# $NetBSD: Makefile,v 1.1.1.1 1999/07/21 22:56:35 garbled Exp $

DISTNAME=		ClanLib-0.1.15
CATEGORIES=		games x11
MASTER_SITES=		http://dark.x.dtu.dk/clansoft/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

DEPENDS+=		Hermes-1.2.5:../../graphics/hermes
DEPENDS+=		Mesa-3.0:../../graphics/Mesa
DEPENDS+=		png-1.0.3:../../graphics/png

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PERL5=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${LOCALBASE}/include/Hermes
CONFIGURE_ARGS+=	--disable-asm386 \
			--enable-libpng \
			--enable-clansound \
			--enable-dyn \
			--enable-network --enable-mesa

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"# CC='cc ${CFLAGS} ${LDFLAGS}'
MAKE_ENV+=		LDFLAGS="${LDFLAGS}"

BROKEN_LIBZ!=ar t /usr/lib/libz.a | grep -w example.o || echo "false"
.if !empty(BROKEN_LIBZ:Mexample.o)
BROKEN= "Update to NetBSD 1.4.1, or recompile /usr/lib/libz without example.c"
.endif

.include "../../mk/bsd.pkg.mk"
