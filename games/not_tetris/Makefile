# $NetBSD: Makefile,v 1.1 2018/09/30 19:26:19 maya Exp $

DISTNAME=	nottetris2-source
PKGNAME=	not_tetris-2.0
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=nottetris2/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stabyourself.net/notpacman
COMMENT=	Gravity-controlled tetris
LICENSE=	public-domain # Specified in https://github.com/Stabyourself/nottetris2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

LOVE_GAME=	not_tetris
LOVE_DATA=	"Not Tetris 2.love"
LOVE_VERSION=	0.7

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
