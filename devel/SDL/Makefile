# $NetBSD: Makefile,v 1.44 2002/11/05 19:25:07 jlam Exp $
#

DISTNAME=	SDL-1.2.5
PKGREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
NASMFLAGS_ELF=		-f elf
NASMFLAGS_a.out=	-f aoutb

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if defined(SDL_USE_NAS)
.  include "../../audio/nas/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--enable-video-aalib
CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"

# Pass in LDFLAGS via SYSTEM_LIBS as it's used as the linker options for
# finding various libraries.  This ensure that any unusual -Wl,-R options
# are noted correctly in the generated sdl-config.
#
CONFIGURE_ENV+=		SYSTEM_LIBS="${LDFLAGS}"

.include "../../mk/ossaudio.buildlink2.mk"
.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
AM_CFLAGS=		-D_PATH_DEV_DSP=\\\"${DEVOSSAUDIO}\\\"
MAKE_ENV+=		AM_CFLAGS="${AM_CFLAGS}"
.endif

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/aalib-x11/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
# Let SDL know that we do not have native pthreads and are using GNU pth.
CONFIGURE_ARGS+=       --disable-pthreads
CONFIGURE_ARGS+=       --enable-pth
.endif

.include "../../mk/bsd.pkg.mk"
