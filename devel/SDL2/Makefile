# $NetBSD: Makefile,v 1.61 2022/01/11 13:02:37 nia Exp $

DISTNAME=	SDL2-2.0.20
CATEGORIES=	devel
MASTER_SITES=	https://www.libsdl.org/release/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer - cross-platform multimedia library
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

# Let pkgsrc handle the rpath.
CONFIGURE_ARGS+=	--disable-rpath

# Explicitly link against libraries.
CONFIGURE_ARGS+=	--disable-alsa-shared
CONFIGURE_ARGS+=	--disable-jack-shared
CONFIGURE_ARGS+=	--disable-libsamplerate-shared
CONFIGURE_ARGS+=	--disable-wayland-shared
CONFIGURE_ARGS+=	--disable-x11-shared

# Deprecated, removed from pkgsrc.
CONFIGURE_ARGS+=	--disable-esd

# SDL has native audio(4) support, avoid building ossaudio(4) support.
CONFIGURE_ARGS.NetBSD+=	--disable-oss

PKGCONFIG_OVERRIDE+=	sdl2.pc.in

CHECK_PORTABILITY_SKIP+=	build-scripts/androidbuildlibs.sh
CHECK_PORTABILITY_SKIP+=	build-scripts/iosbuild.sh

.include "options.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
