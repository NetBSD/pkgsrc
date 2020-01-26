# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:16 rillig Exp $

PKGNAME=	mrrescue-${GITHUB_RELEASE}
DISTNAME=	mrrescue${GITHUB_RELEASE}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonLarsen/}
GITHUB_PROJECT=	mrrescue
GITHUB_RELEASE=	1.02e
EXTRACT_SUFX=	.love

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tangramgames.dk/games/mrrescue/
COMMENT=	Arcade-style fire fighting game
LICENSE=	zlib AND cc-by-sa-v3.0

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR:Q}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}


LOVE_GAME=	mrrescue
LOVE_DATA=	${DISTNAME}.love
LOVE_VERSION=	0.10

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
