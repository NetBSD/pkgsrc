# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 11:13:18 agc Exp $

DISTNAME=		gnuboy-0.9.13
CATEGORIES=		emulators
MASTER_SITES=		http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=		motor@diku.dk
HOMEPAGE=		http://brightrain.aerifal.cx/~laguna/
COMMENT=		gameboy emulator

GNU_CONFIGURE= yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/etc/sample.rc \
	   ${WRKSRC}/CREDITS ${PREFIX}/share/doc/gnuboy/

.include "../../mk/bsd.pkg.mk"
