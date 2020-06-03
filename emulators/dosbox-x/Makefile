# $NetBSD: Makefile,v 1.14 2020/06/03 13:36:26 nia Exp $

DISTNAME=	dosbox-x-0.83.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=joncampbell123/}
GITHUB_TAG=	dosbox-x-v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://dosbox-x.com/
COMMENT=	DOSBox fork with enhancements
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dosbox-x-${GITHUB_TAG}
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf autoreconf automake pkg-config
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

LIBS.NetBSD+=	-lcompat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CPPFLAGS+=	-Dfopen64=fopen
CPPFLAGS+=	-Dftello64=ftello
CPPFLAGS+=	-Dfseeko64=fseeko
.endif

CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-sdl2test
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--enable-sdl2

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-dynrec
CONFIGURE_ARGS+=	--disable-fpu
CONFIGURE_ARGS+=	--disable-unaligned-memory
.else
# LOG: Setting execute permission on the code cache has failed
NOT_PAX_MPROTECT_SAFE+=	bin/dosbox-x
.endif

PKGCONFIG_OVERRIDE+=	vs2015/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdl/sdl.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdl2/sdl2.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/sdlnet/SDL_net.pc.in
PKGCONFIG_OVERRIDE+=	vs2015/zlib/zlib.pc.in

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

CHECK_PORTABILITY_SKIP+=	vs2015/sdl2/build-scripts/androidbuildlibs.sh
CHECK_PORTABILITY_SKIP+=	vs2015/sdl2/build-scripts/iosbuild.sh

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/dosbox.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/dosbox.png
	${INSTALL_DATA} ${FILESDIR}/dosbox-x.desktop \
	    ${DESTDIR}${PREFIX}/share/applications

.include "options.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
