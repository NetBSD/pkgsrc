# $NetBSD: Makefile,v 1.6 2005/02/22 13:44:13 minskim Exp $

DISTNAME=	xfreecell-1.0.5b
CATEGORIES=	games
MASTER_SITES=   http://www2.giganet.net/~nakayama/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@infolaunch.com
HOMEPAGE= 	http://www2.giganet.net/~nakayama/
COMMENT=	Popular freecell card game for X

USE_X11BASE=	yes
USE_GNU_TOOLS+=	make
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/xfreecell
NO_CONFIGURE=	YES

MAKE_ENV+=	GMAKE=${GMAKE:Q}

.include "../../mk/bsd.pkg.mk"
