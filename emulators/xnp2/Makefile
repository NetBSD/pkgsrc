# $NetBSD: Makefile,v 1.38 2022/08/11 05:08:22 gutteridge Exp $

DISTNAME=		xnp2-0.86
PKGREVISION=		15
CATEGORIES=		emulators
MASTER_SITES=		http://www.nonakap.org/np2/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://www.nonakap.org/np2/
COMMENT=		Neko Project II PC-9801 emulator
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_DIRS=		x11

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-build-all
CONFIGURE_ARGS+=	--enable-sdl2

# Workaround for glib2-2.68.0 c++ fallout.
CXXFLAGS+=		-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_66

INSTALLATION_DIRS+=	share/doc/xnp2 ${PKGMANDIR}/ja/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/x11/README.ja \
		${DESTDIR}${PREFIX}/share/doc/xnp2
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnp2.1j	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja/man1/xnp2.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnp21.1j	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja/man1/xnp21.1

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
