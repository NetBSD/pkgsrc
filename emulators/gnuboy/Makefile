# $NetBSD: Makefile,v 1.15 2012/10/23 10:24:03 wiz Exp $

DISTNAME=	gnuboy-1.0.3
PKGREVISION=	2
CATEGORIES=	emulators games
MASTER_SITES=	http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=	njl@sdf.lonestar.org
#HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	Gameboy emulator

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin
BUILDLINK_TRANSFORM+=	rm:-fforce-mem

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gnuboy
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${DESTDIR}${PREFIX}/share/examples/gnuboy/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${DESTDIR}${PREFIX}/share/doc/gnuboy/

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
