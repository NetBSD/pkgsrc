# $NetBSD: Makefile,v 1.11 2007/11/25 11:52:44 wiz Exp $

DISTNAME=	gnuboy-1.0.3
PKGREVISION=	2
CATEGORIES=	emulators games
MASTER_SITES=	http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=	njl@sdf.lonestar.org
#HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	Gameboy emulator

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${PREFIX}/share/examples/gnuboy/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${PREFIX}/share/doc/gnuboy/

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
