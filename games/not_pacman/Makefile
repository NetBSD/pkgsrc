# $NetBSD: Makefile,v 1.3 2020/01/26 17:31:16 rillig Exp $

DISTNAME=	notpacman-source
PKGNAME=	not_pacman-1.4
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=notpacman-1004/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stabyourself.net/notpacman
COMMENT=	Gravity-controlled pacman
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

LOVE_GAME=	not_pacman
LOVE_DATA=	not_pacman.love
LOVE_VERSION=	0.7

.include "../../mk/love.mk"
.include "../../mk/bsd.pkg.mk"
