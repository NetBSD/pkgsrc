# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:40 tv Exp $

DISTNAME=	gnuboy-1.0.3
PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	SDL port of Gameboy emulator

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_BUILDLINK3=	yes
CONFIGURE_ARGS+=--with-sdl

.include "../../devel/SDL/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy-sdl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnuboy-sdl
	${INSTALL_PROGRAM} ${WRKSRC}/sdlgnuboy ${PREFIX}/bin/gnuboy-sdl
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${PREFIX}/share/examples/gnuboy-sdl/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${PREFIX}/share/doc/gnuboy-sdl/

.include "../../mk/bsd.pkg.mk"
