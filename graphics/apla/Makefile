# $NetBSD: Makefile,v 1.1.1.1 2001/06/16 11:40:33 zuntum Exp $
#

DISTNAME=	apla-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://zuntum.net/distfiles/			\
		http://pd37.warszawa.sdi.tpnet.pl/NetBSD/

MAINTAINER=	zuntum@netbsd.org,w.wnuk@zodiac.mimuw.edu.pl
COMMENT=	replacement for aviplay player

DEPENDS+=	avifile-*:../../graphics/avifile-devel
DEPENDS+=	SDL_ttf-*:../../devel/SDL_ttf
DEPENDS+=	libiconv-*:../../converters/libiconv

WRKSRC=		${WRKDIR}/apla

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apla.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
