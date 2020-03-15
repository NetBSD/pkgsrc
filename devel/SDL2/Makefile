# $NetBSD: Makefile,v 1.46 2020/03/15 21:09:47 nia Exp $

DISTNAME=	SDL2-2.0.10
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer - cross-platform multimedia library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake autoreconf
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	sdl2.pc.in

CONFIGURE_ENV+=	SDL_RLD_FLAGS="${COMPILER_RPATH_FLAG}${PREFIX}/lib \
		${COMPILER_RPATH_FLAG}${X11BASE}/lib"

CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ARGS+=	--disable-x11-shared

# Use audio(4) over ossaudio(4) on NetBSD.
CONFIGURE_ARGS.NetBSD+=	--disable-oss

CHECK_PORTABILITY_SKIP+=	build-scripts/androidbuildlibs.sh
CHECK_PORTABILITY_SKIP+=	build-scripts/iosbuild.sh

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

CFLAGS+=	-DPREFIX=\"${PREFIX}\"

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
