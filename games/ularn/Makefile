# $NetBSD: Makefile,v 1.8 2003/09/19 23:08:24 dent Exp $

DISTNAME=		ularn
PKGNAME=		ularn-6.12.92
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.win.tue.nl/pub/games/larn/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://home-13.tiscali-business.nl/~bwaijers/larn/
COMMENT=		Fantasy roguelike game based on vintage larn

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
