# $NetBSD: Makefile,v 1.2 2003/02/14 20:06:00 salo Exp $

DISTNAME=	gnuboy-1.0.3
CATEGORIES=	emulators
MASTER_SITES=	http://gnuboy.unix-fu.org/src/

MAINTAINER=	motor@diku.dk
HOMEPAGE=	http://gnuboy.unix-fu.org/
COMMENT=	gameboy emulator

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/xgnuboy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/etc/sample.rc \
	   ${WRKSRC}/docs/* ${PREFIX}/share/doc/gnuboy/

.include "../../mk/bsd.pkg.mk"
