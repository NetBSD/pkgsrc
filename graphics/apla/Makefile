# $NetBSD: Makefile,v 1.10 2002/08/28 05:31:00 jlam Exp $
#

DISTNAME=	apla-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://pd37.warszawa.sdi.tpnet.pl/NetBSD/

MAINTAINER=	zuntum@netbsd.org,w.wnuk@zodiac.mimuw.edu.pl
COMMENT=	replacement for aviplay player

USE_BUILDLINK2=	YES
USE_X11=	YES

MAKE_ENV+=	AVIFILE_CONFIG=avifile-config
MAKE_ENV+=	SDL_CONFIG=sdl-config
MAKE_ENV+=	FREETYPE_CONFIG=freetype-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apla.1 ${PREFIX}/man/man1

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/avifile-devel/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
