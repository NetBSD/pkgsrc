# $NetBSD: Makefile,v 1.11 2000/10/15 12:06:35 rh Exp $

DISTNAME=		ClanLib-0.2.2
CATEGORIES=		graphics games devel x11
MASTER_SITES=		http://dark.x.dtu.dk/clansoft/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/

DEPENDS+=		Hermes-1.2.6*:../../graphics/hermes
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		pth-*:../../devel/pth

USE_X11BASE=		yes
USE_MESA=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PERL5=		yes

LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${LOCALBASE}/include/Hermes
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-asm386
.else
CONFIGURE_ARGS+=	--disable-asm386
.endif
CONFIGURE_ARGS+=	--enable-libpng
CONFIGURE_ARGS+=	--enable-clansound
CONFIGURE_ARGS+=	--enable-dyn
CONFIGURE_ARGS+=	--enable-network
CONFIGURE_ARGS+=	--enable-mesa
CONFIGURE_ARGS+=	--disable-ggi

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"# CC='cc ${CFLAGS} ${LDFLAGS}'
MAKE_ENV+=		LDFLAGS="${LDFLAGS}"

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "NetBSD"
BROKEN_LIBZ!=${AR} t /usr/lib/libz.a | ${GREP} -w example.o || ${ECHO} "false"
.if !empty(BROKEN_LIBZ:Mexample.o)
BROKEN= "Update to NetBSD 1.4.1, or recompile /usr/lib/libz without example.c"
.endif
.endif
