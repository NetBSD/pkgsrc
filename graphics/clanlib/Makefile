# $NetBSD: Makefile,v 1.38 2004/10/03 00:14:49 tv Exp $

DISTNAME=		ClanLib-0.4.4
PKGREVISION=		6
CATEGORIES=		graphics games devel x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/
COMMENT=		The ClanLib Game SDK

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

.include "../../mk/bsd.prefs.mk"

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
CONFIGURE_ARGS+=	--disable-vidmode

CONFIGURE_ENV+=		perl_exec="${PERL5}"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
MAKE_ENV+=		X11BASE="${X11BASE}"

.include "../../mk/bsd.prefs.mk"

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

.include "../../graphics/hermes/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "NetBSD"
BROKEN_LIBZ!=${AR} t /usr/lib/libz.a | ${GREP} -w example.o || ${ECHO} "false"
.if !empty(BROKEN_LIBZ:Mexample.o)
BROKEN= "Update to NetBSD 1.4.1, or recompile /usr/lib/libz without example.c"
.endif
.endif
