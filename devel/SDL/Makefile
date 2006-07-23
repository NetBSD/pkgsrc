# $NetBSD: Makefile,v 1.72 2006/07/23 16:21:28 wiz Exp $

DISTNAME=	SDL-1.2.11
PKGREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

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

.if ${MACHINE_ARCH} == "i386"
.  include "../../devel/binutils/buildlink3.mk"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
NASMFLAGS_ELF=		-f elf
NASMFLAGS_a.out=	-f aoutb
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
.endif

.include "../../mk/oss.buildlink3.mk"

AM_CFLAGS=		-D_PATH_DEV_DSP="\"${DEVOSSAUDIO}\""
MAKE_ENV+=		AM_CFLAGS=${AM_CFLAGS:Q}

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
