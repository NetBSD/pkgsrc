# $NetBSD: Makefile,v 1.3 2024/01/19 02:34:29 maya Exp $

DISTNAME=	nottetris2-source
PKGNAME=	not_tetris-2.0
PKGREVISION=	1
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

post-extract:
	@${MKDIR} ${WRKDIR}/${LOVE_GAME}_archive
	(cd ${WRKDIR}/${LOVE_GAME}_archive && ${UNZIP_CMD} -qo ${WRKDIR}/*.love)

pre-install:
	(cd ${WRKDIR} && ${UNZIP_CMD} ${LOVE_DATA} ${WRKDIR}/${LOVE_GAME}_archive)

LOVE_GAME=	not_tetris
LOVE_DATA=	"Not Tetris 2.love"
LOVE_VERSION=	0.7

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
