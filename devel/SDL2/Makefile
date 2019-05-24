# $NetBSD: Makefile,v 1.35 2019/05/24 18:13:36 nia Exp $

DISTNAME=	SDL2-2.0.9
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer is a cross-platform multimedia library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake autoreconf
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	sdl2.pc.in

CONFIGURE_ENV+=	SDL_RLD_FLAGS="${COMPILER_RPATH_FLAG}${PREFIX}/lib \
		${COMPILER_RPATH_FLAG}${X11BASE}/lib"

CHECK_PORTABILITY_SKIP+=build-scripts/androidbuildlibs.sh
CHECK_PORTABILITY_SKIP+=build-scripts/iosbuild.sh

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
