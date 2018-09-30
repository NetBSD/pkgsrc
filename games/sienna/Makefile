# $NetBSD: Makefile,v 1.1 2018/09/30 19:28:03 maya Exp $

DISTNAME=	sienna-${GITHUB_RELEASE:S/v//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonLarsen/}
GITHUB_PROJECT=	sienna
GITHUB_RELEASE=	v1.0c
EXTRACT_SUFX=	.love

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tangramgames.dk/games/sienna/
COMMENT=	One button platformer
LICENSE=	zlib AND cc-by-nc-nd-v3.0-license

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR:Q}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}


LOVE_GAME=	sienna
LOVE_DATA=	${DISTNAME}.love
LOVE_VERSION=	0.10

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
