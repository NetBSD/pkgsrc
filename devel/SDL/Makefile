# $NetBSD: Makefile,v 1.112 2013/11/25 12:00:47 wiz Exp $

DISTNAME=	SDL-1.2.15
PKGREVISION=	8
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DX11BASE="\"${X11BASE}\""

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "SunOS"
BUILD_DEPENDS+=		yasm>=0.6.0:../../devel/yasm
NASMFLAGS_ELF=		-f elf
NASMFLAGS_a.out=	-f aoutb
.else
CONFIGURE_ARGS+=	--disable-nasm
.endif

CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M9.*)
LDFLAGS+=	-Wl,-dylib_file -Wl,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.  endif
.endif

.include "../../mk/oss.buildlink3.mk"

AM_CFLAGS=		-D_PATH_DEV_DSP="\"${DEVOSSAUDIO}\""
MAKE_ENV+=		AM_CFLAGS=${AM_CFLAGS:M*:Q}

# Irix comes with GL, which works fine for SDL
.if ${OPSYS} != "IRIX" && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-x11-shared
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
# Let SDL know that we do not have native pthreads and are using GNU pth.
CONFIGURE_ARGS+=	--disable-pthreads
CONFIGURE_ARGS+=	--enable-pth
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
