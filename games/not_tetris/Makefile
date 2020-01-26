# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:17 rillig Exp $

DISTNAME=	nottetris2-source
PKGNAME=	not_tetris-2.0
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=nottetris2/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stabyourself.net/notpacman
COMMENT=	Gravity-controlled tetris
LICENSE=	public-domain # Specified in https://github.com/Stabyourself/nottetris2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

LOVE_GAME=	not_tetris
LOVE_DATA=	"Not Tetris 2.love"
LOVE_VERSION=	0.7

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
