# $NetBSD: Makefile,v 1.7 2001/08/17 21:16:52 jlam Exp $
#

DISTNAME=	apla-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://pd37.warszawa.sdi.tpnet.pl/NetBSD/

MAINTAINER=	zuntum@netbsd.org,w.wnuk@zodiac.mimuw.edu.pl
COMMENT=	replacement for aviplay player

USE_BUILDLINK_ONLY=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apla.1 ${PREFIX}/man/man1

.include "../../graphics/avifile-devel/buildlink.mk"
.include "../../devel/SDL_ttf/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
