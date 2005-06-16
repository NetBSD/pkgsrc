# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:50 jlam Exp $

DISTNAME=	gnuboy-1.0.3
PKGREVISION=	1
CATEGORIES=	emulators games
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	njl@sdf.lonestar.org
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	Gameboy emulator

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/etc/sample.rc \
		${PREFIX}/share/examples/gnuboy/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/docs/* \
		${PREFIX}/share/doc/gnuboy/

.include "../../mk/bsd.pkg.mk"
