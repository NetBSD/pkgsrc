# $NetBSD: Makefile,v 1.3 2001/06/26 21:45:55 zuntum Exp $
#

DISTNAME=	apla-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://pd37.warszawa.sdi.tpnet.pl/NetBSD/

MAINTAINER=	zuntum@netbsd.org,w.wnuk@zodiac.mimuw.edu.pl
COMMENT=	replacement for aviplay player

USE_BUILDLINK_ONLY=	YES

MAKE_ENV+=	SDL_CONFIG="${BUILDLINK_CONFIG_WRAPPER.SDL}"
MAKE_ENV+=	AVIFILE_CONFIG="${BUILDLINK_CONFIG_WRAPPER.avifile}"

WRKSRC=		${WRKDIR}/apla

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apla ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/apla.1 ${PREFIX}/man/man1

.include "../../graphics/avifile/buildlink.mk"
.include "../../devel/SDL_ttf/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
