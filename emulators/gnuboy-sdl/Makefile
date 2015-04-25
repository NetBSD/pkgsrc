# $NetBSD: Makefile,v 1.15 2015/04/25 14:20:45 tnn Exp $

DISTNAME=	gnuboy-1.0.3
PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	SDL port of Gameboy emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sdl

INSTALLATION_DIRS=	bin share/doc/gnuboy-sdl share/examples/gnuboy-sdl
BUILDLINK_TRANSFORM+=	rm:-fforce-mem

.include "../../devel/SDL/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdlgnuboy \
		${DESTDIR}${PREFIX}/bin/gnuboy-sdl
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${DESTDIR}${PREFIX}/share/examples/gnuboy-sdl/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${DESTDIR}${PREFIX}/share/doc/gnuboy-sdl/

.include "../../mk/bsd.pkg.mk"
