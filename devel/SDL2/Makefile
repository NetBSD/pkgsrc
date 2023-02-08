# $NetBSD: Makefile,v 1.76 2023/02/08 18:59:43 nia Exp $

DISTNAME=	SDL2-2.26.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_PROJECT=	SDL
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

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
CONFIGURE_ARGS+=	--disable-pulseaudio-shared
CONFIGURE_ARGS+=	--disable-libsamplerate-shared
CONFIGURE_ARGS+=	--disable-wayland-shared
CONFIGURE_ARGS+=	--disable-x11-shared

# Deprecated, removed from pkgsrc.
CONFIGURE_ARGS+=	--disable-esd

# SDL has native audio(4) support, avoid building ossaudio(4) support.
CONFIGURE_ARGS.NetBSD+=	--disable-oss

LDFLAGS.FreeBSD+=	-lusb

.include "../../mk/bsd.prefs.mk"

# Runtime detection is lacking and illegal instruction faults happen
# on e.g. QEMU with -cpu pentium.
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-sse
CONFIGURE_ARGS+=	--disable-ssemath
CONFIGURE_ARGS+=	--disable-sse2
.endif

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
