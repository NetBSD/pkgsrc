# $NetBSD: Makefile,v 1.3 2003/02/16 21:41:08 salo Exp $

DISTNAME=	gnuboy-1.0.3
PKGREVISION=	1
CATEGORIES=	emulators games
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	njl@sdf.lonestar.org
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	gameboy emulator

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${PREFIX}/share/examples/gnuboy/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${PREFIX}/share/doc/gnuboy/

.include "../../mk/bsd.pkg.mk"
