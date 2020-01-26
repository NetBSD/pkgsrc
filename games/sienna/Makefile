# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:17 rillig Exp $

DISTNAME=	sienna-${GITHUB_RELEASE:S/v//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonLarsen/}
GITHUB_PROJECT=	sienna
GITHUB_RELEASE=	v1.0c
EXTRACT_SUFX=	.love

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tangramgames.dk/games/sienna/
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
