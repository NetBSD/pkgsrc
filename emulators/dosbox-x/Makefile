# $NetBSD: Makefile,v 1.39 2022/08/11 05:08:18 gutteridge Exp $

DISTNAME=	dosbox-x-0.83.25
PKGREVISION=	2
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

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

# C++11
GCC_REQD+=	4.7

LIBS.NetBSD+=	-lcompat

CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-sdl2test
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--enable-sdl2

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		nasm>=2.14:../../devel/nasm
.endif

.if ${MACHINE_ARCH} != "i386" && \
    ${MACHINE_ARCH} != "x86_64" && \
    ${MACHINE_ARCH} != "aarch64" && \
    ${MACHINE_ARCH} != "earmv6hf" && \
    ${MACHINE_ARCH} != "earmv7hf"
CONFIGURE_ARGS+=	--disable-dynamic-core
.else
# LOG: Setting execute permission on the code cache has failed
NOT_PAX_MPROTECT_SAFE+=	bin/dosbox-x
.endif

INSTALLATION_DIRS+=	bin share/dosbox-x
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

CHECK_PORTABILITY_SKIP+=	vs/sdl2/build-scripts/*.sh
CHECK_PORTABILITY_SKIP+=	make-flatpak-sdl2.sh
CHECK_PORTABILITY_SKIP+=	make-flatpak.sh
# [[ is used in an developer target that isn't useful for us
CHECK_PORTABILITY_SKIP+=	Makefile.in Makefile.am

BUILDLINK_TRANSFORM+=	rm:-Wno-int-to-void-pointer-cast
BUILDLINK_TRANSFORM+=	rm:-Wno-address-of-packed-member

post-extract:
	dos2unix ${WRKSRC}/include/iconvpp.hpp

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox-x ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/fonts/FREECG98.BMP \
	    ${DESTDIR}${PREFIX}/share/dosbox-x
	${INSTALL_DATA} ${WRKSRC}/contrib/icons/dosbox-x.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/dosbox-x.png
	${INSTALL_DATA} ${WRKSRC}/contrib/linux/com.dosbox_x.DOSBox-X.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
	    ${DESTDIR}${PREFIX}/share/dosbox-x
	${INSTALL_DATA} ${WRKSRC}/dosbox-x.reference.conf \
	    ${DESTDIR}${PREFIX}/share/dosbox-x

.include "options.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
