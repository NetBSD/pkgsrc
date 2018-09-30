# $NetBSD: Makefile,v 1.2 2018/09/30 19:29:18 maya Exp $

DISTNAME=	notpacman-source
PKGNAME=	not_pacman-1.4
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=notpacman-1004/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stabyourself.net/notpacman
COMMENT=	Gravity-controlled pacman
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

LOVE_GAME=	not_pacman
LOVE_DATA=	not_pacman.love
LOVE_VERSION=	0.7

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
