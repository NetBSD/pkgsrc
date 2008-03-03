# $NetBSD: Makefile,v 1.9 2008/03/03 19:21:38 jlam Exp $

DISTNAME=	gnuboy-1.0.3
PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	SDL port of Gameboy emulator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sdl

.include "../../devel/SDL/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gnuboy-sdl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gnuboy-sdl
	${INSTALL_PROGRAM} ${WRKSRC}/sdlgnuboy \
		${DESTDIR}${PREFIX}/bin/gnuboy-sdl
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${DESTDIR}${PREFIX}/share/examples/gnuboy-sdl/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${DESTDIR}${PREFIX}/share/doc/gnuboy-sdl/

.include "../../mk/bsd.pkg.mk"
