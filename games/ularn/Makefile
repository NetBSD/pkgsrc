# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 15:27:30 agc Exp $

DISTNAME=		ularn
PKGNAME=		ularn-6.12.92
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.win.tue.nl/pub/games/larn/ \
			http://amaterasu.math.orst.edu:8080/~sharpej/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.win.tue.nl/games/roguelike/larn/
COMMENT=		fantasy roguelike game based on vintage larn

NO_WRKSUBDIR=		yes
HAS_CONFIGURE=          # defined
CONFIGURE_ENV+=         PREFIX=${LOCALBASE}
CONFIGURE_SCRIPT=       ./Configure
CONFIGURE_ARGS+=        -d

pre-configure:
	${MV} ${WRKSRC}/Configure ${WRKSRC}/Configure.template
	${SED} 's:XXXLIBDIRXXX:${LOCALBASE}/share/Ularn:;\
		s:XXXBINDIRXXX:${LOCALBASE}/bin:' \
		<${WRKSRC}/Configure.template \
		>${WRKSRC}/Configure
	${CHMOD} u+x ${WRKSRC}/Configure

post-install:
	${CHGRP} games ${LOCALBASE}/bin/Ularn
	${CHMOD} g+s ${LOCALBASE}/bin/Ularn
	${CHMOD} g+w ${LOCALBASE}/share/Ularn

.include "../../mk/bsd.pkg.mk"
