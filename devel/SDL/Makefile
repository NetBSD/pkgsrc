# $NetBSD: Makefile,v 1.35 2002/07/13 16:17:33 wiz Exp $
#

DISTNAME=	SDL-1.2.3
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
NASMFLAGS=		-f elf
.else
NASMFLAGS=		-f aoutb
.endif

.ifdef SDL_USE_NAS
.include "../../audio/nas/buildlink.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-pthread-sem
CONFIGURE_ARGS+=	--enable-video-aalib
CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS}"

# Pass in LDFLAGS via SYSTEM_LIBS as it's used as the linker options for
# finding various libraries.  This ensure that any unusual -Wl,-R options
# are noted correctly in the generated sdl-config.
#
CONFIGURE_ENV+=		SYSTEM_LIBS="${LDFLAGS}"

pre-patch:
	cd ${WRKSRC} && ${MKDIR} src/audio/netbsd

post-configure:
	cd ${WRKSRC}/src/audio && ${CP} *.[ch] netbsd/

.include "../../audio/esound/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/aalib-x11/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
