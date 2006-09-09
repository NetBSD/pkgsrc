# $NetBSD: Makefile,v 1.11 2006/09/09 02:42:01 obache Exp $

DISTNAME=	xfreecell-1.0.5b
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=   http://www2.giganet.net/~nakayama/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@infolaunch.com
HOMEPAGE= 	http://www2.giganet.net/~nakayama/
COMMENT=	Popular freecell card game for X

USE_X11BASE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	makefile

WRKSRC=		${WRKDIR}/xfreecell
NO_CONFIGURE=	YES

MAKE_ENV+=	GMAKE=${GMAKE:Q}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
