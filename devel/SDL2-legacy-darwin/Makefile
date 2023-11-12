# $NetBSD: Makefile,v 1.1 2023/11/12 21:28:04 nia Exp $

DISTNAME=	SDL2-2.0.3
CATEGORIES=	devel
MASTER_SITES=	https://libsdl.org/release/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Legacy SDL2 suitable for old Mac OS X versions
LICENSE=	zlib

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

# Let pkgsrc handle the rpath.
CONFIGURE_ARGS+=	--disable-rpath

# Explicitly link against libraries.
CONFIGURE_ARGS+=	--disable-alsa-shared
CONFIGURE_ARGS+=	--disable-pulseaudio-shared
CONFIGURE_ARGS+=	--disable-x11-shared

# Deprecated, removed from pkgsrc.
CONFIGURE_ARGS+=	--disable-esd

CONFIGURE_ARGS+=	--disable-video-wayland
CONFIGURE_ARGS.Darwin+=	--disable-haptic

# Needed to support the older joystick controller.
LDFLAGS.Darwin+=	-framework ForceFeedback

.include "../../mk/bsd.prefs.mk"

# Runtime detection is lacking and illegal instruction faults happen
# on e.g. QEMU with -cpu pentium.
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-sse
CONFIGURE_ARGS+=	--disable-ssemath
CONFIGURE_ARGS+=	--disable-sse2
.endif

PKGCONFIG_OVERRIDE+=	sdl2.pc.in

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
