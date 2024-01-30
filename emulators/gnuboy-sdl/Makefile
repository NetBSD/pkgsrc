# $NetBSD: Makefile,v 1.18 2024/01/30 14:21:47 ryoon Exp $

PKGREVISION= 1
.include "../../emulators/gnuboy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}

COMMENT=	Fast gameboy emulator (SDL2 version)

CONFIGURE_ARGS+=	--with-sdl2
CONFIGURE_ARGS+=	--with-sound=sdl

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/doc/gnuboy-sdl
INSTALLATION_DIRS+=	share/examples/gnuboy-sdl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdl2gnuboy \
		${DESTDIR}${PREFIX}/bin/gnuboy-sdl
	${INSTALL_MAN} ${FILESDIR}/gnuboy-sdl.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/gnuboy-sdl.6
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${DESTDIR}${PREFIX}/share/examples/gnuboy-sdl/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${DESTDIR}${PREFIX}/share/doc/gnuboy-sdl/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
