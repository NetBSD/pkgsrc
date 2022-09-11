# $NetBSD: Makefile,v 1.68 2022/09/11 12:51:05 wiz Exp $

DISTNAME=	SDL2-2.24.0
PKGREVISION=	2
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		gsort
SUBST_STAGE.gsort=	pre-configure
SUBST_MESSAGE.gsort=	BSD sort has no -V option
SUBST_FILES.gsort+=	configure
SUBST_FILES.gsort+=	configure.ac
SUBST_SED.gsort+=	-e 's,sort -V,sort,g'
.endif

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
