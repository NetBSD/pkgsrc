# $NetBSD: Makefile,v 1.23 2001/10/23 13:14:56 jlam Exp $

DISTNAME=		ClanLib-0.4.4
CATEGORIES=		graphics games devel x11
MASTER_SITES=		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.clanlib.org/
COMMENT=		The ClanLib Game SDK

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

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

.include "../../mk/bsd.prefs.mk"

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/hermes/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "NetBSD"
BROKEN_LIBZ!=${AR} t /usr/lib/libz.a | ${GREP} -w example.o || ${ECHO} "false"
.if !empty(BROKEN_LIBZ:Mexample.o)
BROKEN= "Update to NetBSD 1.4.1, or recompile /usr/lib/libz without example.c"
.endif
.endif
