# $NetBSD: Makefile,v 1.2 2004/03/17 09:58:03 grant Exp $
#

DISTNAME=	apla-1.0.3
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://pd37.warszawa.sdi.tpnet.pl/NetBSD/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Replacement for aviplay player

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
.include "../../multimedia/avifile-devel/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
