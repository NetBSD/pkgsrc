# $NetBSD: Makefile,v 1.41 2002/08/27 18:19:44 jlam Exp $
#

DISTNAME=	SDL-1.2.3
PKGREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
NASMFLAGS=		-f elf
.else
NASMFLAGS=		-f aoutb
.endif

.ifdef SDL_USE_NAS
.  include "../../audio/nas/buildlink2.mk"
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
	cd ${WRKSRC} && ${MKDIR} src/joystick/bsd
	${CP} ${FILESDIR}/[MS]* ${WRKSRC}/src/joystick/bsd

post-configure:
	cd ${WRKSRC}/src/audio && ${CP} *.[ch] netbsd/

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/aalib-x11/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
