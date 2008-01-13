# $NetBSD: Makefile,v 1.81 2008/01/13 15:57:59 wiz Exp $

DISTNAME=	SDL-1.2.13
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

PKG_DESTDIR_SUPPORT=	user-destdir

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

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "SunOS"
BUILD_DEPENDS+=		yasm>=0.6.0:../../devel/yasm
NASMFLAGS_ELF=		-f elf
NASMFLAGS_a.out=	-f aoutb
.else
CONFIGURE_ARGS+=	--disable-nasm
.endif

.if ${OPSYS:MNetBSD}
CONFIGURE_ARGS+=	--disable-video-wscons
.endif

CONFIGURE_ARGS+=	--enable-dlopen
CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"

# buildlink passthru the directories required for the Cocoa framework
# on Darwin if they exist.
.if ${OPSYS} == "Darwin"
COCOA_DIRS+=			/System /Library /Developer
.  for dir in ${COCOA_DIRS}
.    if exists(${dir})
BUILDLINK_PASSTHRU_DIRS+=	${dir}
.    endif
.  endfor

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.  if !empty(OS_VERSION:M9.*)
LDFLAGS+=	-Wl,-dylib_file -Wl,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.  endif

.endif


.include "../../mk/oss.buildlink3.mk"

AM_CFLAGS=		-D_PATH_DEV_DSP="\"${DEVOSSAUDIO}\""
MAKE_ENV+=		AM_CFLAGS=${AM_CFLAGS:M*:Q}

# Irix comes with GL, which works fine for SDL
.if ${OPSYS} != "IRIX" && ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
# Let SDL know that we do not have native pthreads and are using GNU pth.
CONFIGURE_ARGS+=	--disable-pthreads
CONFIGURE_ARGS+=	--enable-pth
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
