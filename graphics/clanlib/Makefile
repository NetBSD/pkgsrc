# $NetBSD: Makefile,v 1.29 2002/09/21 12:49:55 jlam Exp $

DISTNAME=		ClanLib-0.4.4
PKGREVISION=		2
CATEGORIES=		graphics games devel x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/
COMMENT=		The ClanLib Game SDK

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
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

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
MAKE_ENV+=		X11BASE="${X11BASE}"

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "NetBSD"
BROKEN_LIBZ!=${AR} t /usr/lib/libz.a | ${GREP} -w example.o || ${ECHO} "false"
.if !empty(BROKEN_LIBZ:Mexample.o)
BROKEN= "Update to NetBSD 1.4.1, or recompile /usr/lib/libz without example.c"
.endif
.endif
