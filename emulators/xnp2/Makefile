# $NetBSD: Makefile,v 1.27 2018/11/12 03:52:02 ryoon Exp $

DISTNAME=		xnp2-0.86
PKGREVISION=		6
CATEGORIES=		emulators
MASTER_SITES=		http://www.nonakap.org/np2/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://www.nonakap.org/np2/
COMMENT=		Neko Project II PC-9801 emulator
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_DIRS=		x11

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-build-all
# XXX audio/SDL2_mixer requires multimedia/smpeg2 but it conflicts with
#     multimedia/smpeg which is required by audio/SDL_mixer
CONFIGURE_ARGS+=	--disable-sdl2

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
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
